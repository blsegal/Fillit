/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blsegal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:09:12 by tmilon            #+#    #+#             */
/*   Updated: 2018/12/02 18:04:56 by blsegal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_move_left(t_tetri *lst, int pos)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			lst[pos].tab[y * 5 + x] = lst[pos].tab[y * 5 + x + 1];
			x++;
		}
		y++;
	}
	lst[pos].tab[3] = '.';
	lst[pos].tab[8] = '.';
	lst[pos].tab[13] = '.';
	lst[pos].tab[18] = '.';
}

void	ft_move_top(t_tetri *lst, int pos)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			lst[pos].tab[y * 5 + x] = lst[pos].tab[(y + 1) * 5 + x];
			x++;
		}
		y++;
	}
	lst[pos].tab[15] = '.';
	lst[pos].tab[16] = '.';
	lst[pos].tab[17] = '.';
	lst[pos].tab[18] = '.';
}

void	ft_replace_if_void(t_tetri *lst, int pos)
{
	while (lst[pos].tab[0] != '#' && lst[pos].tab[1] != '#' &&
			lst[pos].tab[2] != '#' && lst[pos].tab[3] != '#')
		ft_move_top(lst, pos);
	while (lst[pos].tab[0] != '#' && lst[pos].tab[5] != '#' &&
			lst[pos].tab[10] != '#' && lst[pos].tab[15] != '#')
		ft_move_left(lst, pos);
}

void	ft_replace_to_alpha(t_tetri *lst, int pos)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst[pos].tab[y * 5 + x] == '#')
				lst[pos].tab[y * 5 + x] = pos + 'A';
			x++;
		}
		y++;
	}
}

void	ft_replace(t_tetri *lst)
{
	int		i;

	i = 0;
	while (lst[i].isvalid == 1)
	{
		ft_replace_if_void(lst, i);
		ft_width(&lst[i]);
		ft_height(&lst[i], 0, 0);
		ft_setadj(&lst[i]);
		ft_replace_to_alpha(lst, i);
		i++;
	}
}
