/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:57:10 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 13:49:57 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int				main(void)
{
	int			i;
	t_graph		*graph;

	graph = init_graph(4);

	i = 0;
	while (i < graph->vertices)
		graph->visited[i++] = 0;
	i = 0;
	while (i < graph->vertices)
		graph->queue[i++] = 0;

    add_uni_edge(graph->matrix, 0, 1);
    add_uni_edge(graph->matrix, 1, 3);
    add_uni_edge(graph->matrix, 0, 2);

    print_matrix(graph->matrix, graph->vertices);
	
	printf("DFS\n");
	dfs(graph, 0);
	
	i = 0;
	while (i < graph->vertices)
		graph->visited[i++] = 0;
	i = 0;
	while (i < graph->vertices)
		graph->queue[i++] = 0;

	printf("BFS\n");
	bfs(graph, 0);

    // addEdge(adjMatrix,0,1);
    // addEdge(adjMatrix,0,2);
    // addEdge(adjMatrix,0,3);
    // addEdge(adjMatrix,1,3);
    // addEdge(adjMatrix,1,4);
    // addEdge(adjMatrix,2,3);
    // addEdge(adjMatrix,3,4);

	ft_delptr((char ***)&(graph->matrix), graph->vertices - 1);
	ft_strdel((char **)&(graph->visited));
	ft_strdel((char **)&(graph->queue));
	ft_strdel((char **)&(graph));
    return 0;
}

// void	__attribute__((destructor)) leaks(void)
// {
// 	while (1)
// 		;
// }