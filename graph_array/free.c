/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:18:30 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 19:19:32 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	free_all(t_graph *graph)
{
	t_sht_path *tmp;
	
	ft_delptr((char ***)&(graph->matrix), graph->vertices - 1);
	ft_strdel((char **)&(graph->visited));
	ft_strdel((char **)&(graph->parent));
	ft_strdel((char **)&(graph->dist));
	ft_strdel((char **)&(graph->shortest_path_tree));
	ft_strdel((char **)&(graph->queue));

	while (graph->s_path)
	{
		tmp = graph->s_path->next;
		free(graph->s_path);
		graph->s_path = NULL;
		graph->s_path = tmp;
	}
	ft_strdel((char **)&(graph));
}