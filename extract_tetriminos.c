/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:49:57 by tmilon            #+#    #+#             */
/*   Updated: 2017/12/23 11:31:46 by tmilon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_alloc(t_tetri *lst, char *buf)
{
	int		n;
	int		i;

	n = 0;
	n = (ft_strlen(buf) + 1) / 21;
	i = 0;
	if ((lst = malloc(sizeof(t_tetri) * (n + 1))) == 0)
		ft_abort("erreur dans ftalloc");
	while (i < n)
	{
		lst[i].isvalid = 1;
		lst[i].tab[19] = '\0';
		i++;
	}
	lst[i].isvalid = 0;
	lst[0].length = i;
	return (lst);
}

t_tetri	*ft_fill_lst(char *buf)
{
	t_tetri	*lst;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	lst = NULL;
	lst = ft_alloc(lst, buf);
	while (lst[nb].isvalid)
	{
		ft_memcpy(lst[nb].tab, buf, 19);
		buf += 21;
		nb++;
	}
	return (lst);
}

void	ft_check_nbdiese(t_tetri *lst)
{
	int		i;
	int		y;
	int		z;
	int		nb;

	i = 0;
	while (i < lst[0].length)
	{
		y = 0;
		nb = 0;
		while (y < 4)
		{
			z = 0;
			while (z < 5)
			{
				if (lst[i].tab[y * 5 + z] == '#')
					nb++;
				z++;
			}
			y++;
		}
		if (nb != 4)
			ft_abort("erreur dans nbdiese");
		i++;
	}
}

void	ft_check_place(t_tetri lst, int x, int y)
{
	int		i;

	i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst.tab[y * 5 + x] == '#')
			{
				if (lst.tab[(y + 1) * 5 + x] == '#')
					i++;
				if (lst.tab[(y - 1) * 5 + x] == '#')
					i++;
				if (lst.tab[y * 5 + x + 1] == '#')
					i++;
				if (lst.tab[y * 5 + x - 1] == '#')
					i++;
			}
			x++;
		}
		y++;
	}
	if (i < 6)
		ft_abort("nope");
}

void	ft_check_lst(t_tetri *lst)
{
	int	i;

	i = 0;
	while (lst[i].isvalid == 1)
		ft_check_place(lst[i++], 0, 0);
	ft_check_nbdiese(lst);
}
