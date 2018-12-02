/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blsegal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:29:00 by blsegal           #+#    #+#             */
/*   Updated: 2017/12/25 00:31:48 by tmilon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		count_tetri(t_tetri *lst)
{
	int		ret;

	ret = 0;
	while (lst[ret].isvalid)
		ret++;
	return (ret);
}

void	print_map(int **solution, int taille_map, int max)
{
	char	map[taille_map * taille_map];
	int		decal;

	decal = 0;
	ft_memset(map, '.', taille_map * taille_map);
	while (decal < max)
	{
		map[solution[decal][0]] = 'A' + decal;
		map[solution[decal][1]] = 'A' + decal;
		map[solution[decal][2]] = 'A' + decal;
		map[solution[decal][3]] = 'A' + decal;
		decal++;
	}
	decal = 0;
	while (decal < taille_map * taille_map)
	{
		if (decal % taille_map == 0 && decal > 0)
			ft_putchar('\n');
		ft_putchar(map[decal]);
		decal++;
	}
	ft_putchar('\n');
}

void	ft_resolve(t_tetri *lst)
{
	int		taille_map;
	int		found_smallest_size;
	int		i;
	t_list	**matrix;
	int		**solution;

	found_smallest_size = -1;
	i = 0;
	solution = malloc((lst[0].length + 1) * sizeof(int *));
	solution[lst[0].length] = NULL;
	if ((taille_map = ft_sqrt(count_tetri(lst) * 4)) == 0)
		ft_abort("problem taille map");
	matrix = (t_list **)malloc(count_tetri(lst) * sizeof(t_list *));
	while (i < lst[0].length)
		matrix[i++] = NULL;
	while (found_smallest_size != 1 && taille_map < 15 * 15)
	{
		if (initmatrix(matrix, lst, taille_map) == 1)
			found_smallest_size = backtracking(&lst, matrix, solution, 0);
		while (--i >= 0)
			ft_lstdel(&matrix[i], *free_node);
		taille_map++;
	}
	print_map(solution, taille_map - 1, lst[0].length);
}

void	ft_abort(char *error)
{
	(void)error;
	ft_putendl("error");
	exit(1);
}

int		main(int argc, char **argv)
{
	char		*buf;
	t_tetri		*lst;

	if (argc != 2)
	{
		ft_putstr("usage : ./fillit path/to/file\n");
		return (1);
	}
	buf = malloc(sizeof(char) * 551);
	ft_get_file(&buf, argv[1]);
	lst = ft_fill_lst(buf);
	ft_check_lst(lst);
	ft_replace(lst);
	ft_resolve(lst);
	free(buf);
	return (0);
}
