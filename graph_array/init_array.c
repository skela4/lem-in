/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:05:16 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 19:10:46 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int			*init_spt(t_graph *graph)
{
	int				i;
	int				*shortest_path_tree;

	i = 0;
	shortest_path_tree = (int *)malloc(sizeof(*shortest_path_tree) * graph->vertices);
	while (i < graph->vertices)
	{
		shortest_path_tree[i] = 0;
		i++;
	}
	return (shortest_path_tree);
}

int			*init_dist(t_graph *graph)
{
	int				i;
	int				*dist;

	i = 0;
	dist = (int *)malloc(sizeof(*dist) * graph->vertices);
	while (i < graph->vertices)
	{
		dist[i] = INT_MAX;
		i++;
	}
	return (dist);
}

int			*init_parent(t_graph *graph)
{
	int				i;
	int				*parent;

	i = 0;
	parent = (int *)malloc(sizeof(*parent) * graph->vertices);
	while (i < graph->vertices)
	{
		parent[i] = -1;
		i++;
	}
	return (parent);
}

int			init_array(t_graph *graph)
{
	graph->dist = init_dist(graph);
	if (!graph->dist)
	{
		ft_strdel((char **)graph);
		return (0);
	}
	graph->shortest_path_tree = init_spt(graph);
	if (!graph->shortest_path_tree)
	{
		ft_strdel((char **)graph->dist);
		ft_strdel((char **)graph);
		return (0);
	}
	graph->parent = init_parent(graph);
	if (!graph->parent)
	{
		ft_strdel((char **)graph->dist);
		ft_strdel((char **)graph->shortest_path_tree);
		ft_strdel((char **)graph);
		return (0);
	}
	return (1);
}