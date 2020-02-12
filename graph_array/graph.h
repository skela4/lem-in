/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:03:55 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/06 02:20:58 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct			s_sht_path
{
	int					index;
	struct s_sht_path 	*next;
}						t_sht_path;

typedef struct			s_graph
{
	int					**matrix;
	int					vertices;
	int					edges;
	int					*visited;
	int					*parent;
	int					*dist;
	int					*shortest_path_tree;
	int					*queue;
	t_sht_path			*s_path;
}						t_graph;


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

int				*init_spt(t_graph *graph);
int				*init_dist(t_graph *graph);
int				*init_parent(t_graph *graph);
int				init_array(t_graph *graph);

int				dijkstra(t_graph *graph, int src, int dest);
void			BellmanFord(t_graph *graph, int src, int dest);

void			negate_edge(t_graph *graph);

void			free_all(t_graph *graph);
