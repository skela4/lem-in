/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:42:50 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/02/05 10:43:01 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void    ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void    ft_strdel(char **as)
{
	if (as && *as)
		ft_memdel((void **)as);
}

void	ft_delptr(char ***ptr, int i)
{
	char	**obj;

	obj = *ptr;
	while (i >= 0)
	{
		if (obj[i])
			ft_strdel(&obj[i]);
		--i;
	}
	free(*ptr);
	ptr = NULL;
}