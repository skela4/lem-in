/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:57:10 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 20:36:45 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int				main(void)
{
	int			i;
	t_graph		*graph;

	graph = init_graph(8);

	i = 0;
	while (i < graph->vertices)
		graph->visited[i++] = 0;
	i = 0;
	while (i < graph->vertices)
		graph->queue[i++] = 0;

	add_uni_edge(graph->matrix, 0, 1);
    add_uni_edge(graph->matrix, 0, 2);
    add_uni_edge(graph->matrix, 1, 3);
	add_uni_edge(graph->matrix, 2, 4);
	add_uni_edge(graph->matrix, 2, 5);
    add_uni_edge(graph->matrix, 3, 4);
    add_uni_edge(graph->matrix, 4, 7);
    add_uni_edge(graph->matrix, 5, 4);
    add_uni_edge(graph->matrix, 5, 6);
    add_uni_edge(graph->matrix, 6, 7);

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

	dijkstra(graph, 0, 7);
	negate_edge(graph);
    print_matrix(graph->matrix, graph->vertices);

	free_all(graph);
    return (0);
}

// void	__attribute__((destructor)) leaks(void)
// {
// 	while (1)
// 		;
// }