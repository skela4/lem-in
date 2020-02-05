/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:15:23 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 20:45:23 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_graph			*init_graph(int vertices)
{
	t_graph		*graph;

	graph = (t_graph *)malloc(sizeof(*graph));
	if (!graph)
		return (NULL);
	graph->vertices = vertices;
	if (!(graph->matrix = init_matrix(graph->matrix, graph->vertices, 0)))
	{
		ft_strdel((char **)graph);
		return (NULL);
	}
	if (!(graph->visited = (int *)malloc(sizeof(*(graph->visited)) * graph->vertices)))
	{
		ft_delptr((char ***)&(graph->matrix), graph->vertices - 1);
		ft_strdel((char **)graph);
		return (NULL);
	}
	if (!(graph->queue = (int *)malloc(sizeof(*(graph->queue)) * graph->vertices)))
	{
		ft_strdel((char **)&(graph->visited));
		ft_delptr((char ***)&(graph->matrix), graph->vertices - 1);
		ft_strdel((char **)graph);
		return (NULL);
	}
	return (graph);
}

void			dfs(t_graph *graph, int src)
{
	int			i;

	i = 0;
	graph->visited[src] = 1;
	printf("seen %d\n", src);
	while (i < graph->vertices)
	{
		if (!graph->visited[i] && graph->matrix[src][i] == 1)
			dfs(graph, i);
		i++;
	}
}

void			bfs(t_graph *graph, int src)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	graph->queue[i] = src;
	graph->visited[src] = 1;
	while (i < graph->vertices)
	{
		j = 0;
		src = graph->queue[i];
		printf("seen %d\n", src);
		while (j < graph->vertices)
		{
			if (!graph->visited[j] && graph->matrix[src][j] == 1)
			{
				graph->queue[k + 1] = j;
				graph->visited[j] = 1;
				k++;
			}
			j++;
		}
		i++;
	}

}

int					min_dist(int *dist, int *sptSet, int size)
{
	int				i;
    int				min;
	int				min_index; 

	i = 0;
	min = INT_MAX;
	while (i < size)
	{
		if (sptSet[i] == 0 && dist[i] <= min)
		{
        	min = dist[i];
			min_index = i;
		}
		i++;
	}
    return (min_index);
}
  
void 				get_path(int *parent, int j, t_sht_path *path)
{
	t_sht_path 		*tmp;
	t_sht_path 		*node;

	tmp = path;
    if (parent[j] == -1) 
        return;
	node = (t_sht_path *)malloc(sizeof(t_sht_path));
    get_path(parent, parent[j], path); 
	if (tmp->index == -1)
	{
		tmp->index = j;
		node->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		node->index = j;
		node->next = NULL;
		tmp->next = node;
	}
} 

void 						get_shorter_path(int *parent, int src, int dest, t_sht_path *path) 
{
	t_sht_path 				*tmp;

	tmp = path;
	tmp->index = src;
    get_path(parent, dest, path); 
} 

int						dijkstra(t_graph *graph, int src, int dest)
{
	int						i;
	int						u;
	int						v;

	if (!init_array(graph))
		return (0);
	graph->dist[0] = src;
	i = -1;
	while (++i < graph->vertices - 1)
	{
    	u = min_dist(graph->dist, graph->shortest_path_tree, graph->vertices); 
        graph->shortest_path_tree[u] = 1;
		v = -1;
		while (++v < graph->vertices)
		{
			if (!graph->shortest_path_tree[v] && graph->matrix[u][v]
			&& graph->dist[u] != INT_MAX && graph->dist[u] + graph->matrix[u][v] < graph->dist[v])
			{
				graph->parent[v] = u;
				graph->dist[v] = graph->dist[u] + graph->matrix[u][v];
			}
		}
	}
	graph->s_path = (t_sht_path *)malloc(sizeof(t_sht_path));
	graph->s_path->next = NULL;
	get_shorter_path(graph->parent, 0, dest, graph->s_path);
	return (1);
}

void			print_path(t_sht_path *tmp)
{
	while (tmp)
	{
		printf("%d \n", tmp->index);
		tmp = tmp->next;
	}
}

void			negate_edge(t_graph *graph)
{
	int			i;
	int			j;
	int			k;
	t_sht_path *tmp;

	print_path(graph->s_path);
	tmp = graph->s_path;
	k = 0;
	while (k < graph->vertices)
	{	
		i = 0;
		while (i < graph->vertices)
		{
			j = 0;
			while (j < graph->vertices)
			{
				if (tmp && tmp->next
				&& i == tmp->index && j == tmp->next->index)
				{
					graph->matrix[i][j] = -1;
					tmp = tmp->next;
				}
				j++;
			}
			i++;
		}
		k++;
	}
}

// int						dijkstra(t_graph *graph, int src, int dest)
// void 					BellmanFord(int graph[][3], int V, int E, int src) 
void BellmanFord(t_graph *graph, int src, int dest) 
{ 
    int dis[V]; 
    for (int i = 0; i < V; i++) 
        dis[i] = INT_MAX; 

    dis[src] = 0; 

    for (int i = 0; i < V - 1; i++) { 
  
        for (int j = 0; j < E; j++) { 
            if (dis[graph[j][0]] + graph[j][2] < 
                               dis[graph[j][1]]) 
                dis[graph[j][1]] =  
                  dis[graph[j][0]] + graph[j][2]; 
        } 
    } 

    for (int i = 0; i < E; i++) { 
        int x = graph[i][0]; 
        int y = graph[i][1]; 
        int weight = graph[i][2]; 
        if (dis[x] != INT_MAX && 
                   dis[x] + weight < dis[y]) 
            cout << "Graph contains negative"
                    " weight cycle"
                 << endl; 
    } 
  
    cout << "Vertex Distance from Source" << endl; 
    for (int i = 0; i < V; i++) 
        cout << i << "\t\t" << dis[i] << endl; 
} 