/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blsegal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 09:30:48 by tmilon            #+#    #+#             */
/*   Updated: 2018/12/02 18:04:26 by blsegal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_setadj(t_tetri *lst)
{
	int	count;
	int	x;
	int	xorigi;
	int	y;

	count = 0;
	y = 0;
	while (y < 4 && count < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst->tab[y * 5 + x] == '#')
			{
				if (count == 0)
					xorigi = x;
				lst->hadjust[count] = y;
				lst->wadjust[count] = x - xorigi;
				count++;
			}
			x++;
		}
		y++;
	}
}

void	ft_width(t_tetri *lst)
{
	int		x;
	int		y;
	int		nb;
	int		nb2;

	y = 0;
	nb = 0;
	nb2 = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst->tab[y * 5 + x] == '#')
				nb = x + 1;
			x++;
		}
		if (nb >= nb2)
			nb2 = nb;
		nb = 0;
		y++;
	}
	lst->width = nb2;
}

void	ft_height(t_tetri *lst, int nb, int nb2)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst->tab[y * 5 + x] == '#')
			{
				nb++;
				y++;
				x = -1;
			}
			x++;
		}
		if (nb >= nb2)
			nb2 = nb;
		nb = 0;
		y++;
	}
	lst->height = nb2;
}
