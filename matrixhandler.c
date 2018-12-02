/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:55:07 by tmilon            #+#    #+#             */
/*   Updated: 2017/12/22 21:57:24 by tmilon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

t_list	*add_node(t_tetri bloc, int i, int j, int max)
{
	int		k;
	int		spots[4];
	t_list	*newnode;

	k = 0;
	while (k < 4)
	{
		spots[k] = j + bloc.wadjust[k] + (i + bloc.hadjust[k]) * max;
		k++;
	}
	newnode = ft_lstnew(spots, 4 * sizeof(int));
	return (newnode);
}

void	free_node(void *d, size_t n)
{
	free(d);
	d = NULL;
	(void)n;
}

int		canbeadded(t_tetri bloc, int i, int j, int max)
{
	int	k;
	int	max_decal;

	k = 0;
	max_decal = 0;
	while (k < 4)
	{
		if (bloc.wadjust[k] < max_decal)
			max_decal = bloc.wadjust[k];
		if (j + bloc.wadjust[k++] < 0)
			return (0);
	}
	if (bloc.width + j + max_decal > max ||
			bloc.width + j + max_decal < 0 || bloc.height + i > max)
		return (0);
	return (1);
}

int		all_tetri_added(t_list **matrix, int blocs)
{
	int i;

	i = 0;
	while (i < blocs)
	{
		if (matrix[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

int		initmatrix(t_list **matrix, t_tetri *blocs, int max)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < blocs[0].length)
	{
		while (i < max)
		{
			while (j < max)
			{
				if (canbeadded(blocs[k], i, j, max))
					ftb_lstpush(&matrix[k], add_node(blocs[k], i, j, max));
				j++;
			}
			i++;
			j = 0;
		}
		i = 0;
		k++;
	}
	return (all_tetri_added(matrix, blocs[0].length));
}
