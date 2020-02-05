/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:14:21 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 11:14:55 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int			**init_matrix(int **matrix, int n_node, int value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (n_node <= 0)
		return (NULL);
	matrix = (int **)malloc(sizeof(*matrix) * n_node);
	if (!matrix)
		return (NULL);
	while (i < n_node)
	{
		matrix[i] = (int *)malloc(sizeof(**matrix) * n_node);
		if (!matrix[i])
		{
			ft_delptr((char ***)&matrix, i);
			return (NULL);
		}
		j = 0;
		while (j < n_node)
		{
			matrix[i][j] = value;
			j++;
		}
		++i;
	}
	return (matrix);
}

void			print_matrix(int **matrix, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
            printf("%d ", matrix[i][j]);
			j++;
		}
        printf("\n");
		i++;
	}
}