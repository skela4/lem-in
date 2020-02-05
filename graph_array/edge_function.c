/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:14:18 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 13:51:13 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void			add_uni_edge(int **matrix, int src, int dest)
{
	matrix[src][dest] = 1;
}

void			add_bid_edge(int **matrix, int src, int dest)
{
	matrix[src][dest] = 1;
	matrix[dest][src] = 1;
}