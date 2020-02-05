/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:15:23 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 13:49:17 by aahizi-e         ###   ########.fr       */
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
