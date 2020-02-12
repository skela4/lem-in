/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijsktra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 07:17:55 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/08 08:14:55 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define V 4

void print_solution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

int min_distance(int dist[], bool spt_set[])
{
	int v;
	int min;
	int min_index;

	v = 0;
	min = INT_MAX;
	while (v < V)
	{
		if (spt_set[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
		v++;
	}
	return (min_index);
}

void dijkstra(int graph[V][V], int src)
{
	int u;
	int dist[V];
	bool spt_set[V];

	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		spt_set[i] = false;
	}
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++)
	{
		u = min_distance(dist, spt_set);
		spt_set[u] = true;
		for (int v = 0; v < V; v++)
		{
			if (!spt_set[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}
	print_solution(dist);
}

int main(void)
{
	static int graph[V][V] =
	{
		{0, 2, 0, 3},
		{2, 0, 1, 2},
		{0, 1, 0, 0},
		{3, 2, 0, 0}
	};
	dijkstra(graph, 0);
	return (0);
}
