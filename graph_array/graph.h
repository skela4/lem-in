/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:03:55 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 13:50:53 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_graph
{
	int			**matrix;
	int			vertices;
	int			*visited;
	int			*queue;
}				t_graph;


void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_delptr(char ***ptr, int i);

t_graph			*init_graph(int vertices);

int				**init_matrix(int **matrix, int n_node, int value);
void			print_matrix(int **matrix, int size);

void			add_uni_edge(int **matrix, int src, int dest);
void			add_bid_edge(int **matrix, int src, int dest);

void			dfs(t_graph *graph, int src);
void			bfs(t_graph *graph, int src);
