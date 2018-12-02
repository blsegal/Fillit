/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:57:29 by tmilon            #+#    #+#             */
/*   Updated: 2017/12/22 15:46:02 by tmilon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	comparearray(int *ar1, int *ar2)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (i < 4)
	{
		while (i2 < 4)
			if (ar1[i] == ar2[i2++])
				return (0);
		i++;
		i2 = 0;
	}
	return (1);
}

int	next_fits(int **solution, int *elem, int max)
{
	int	i;

	i = 0;
	while (i < max)
		if (comparearray(elem, solution[i++]) == 0)
			return (0);
	return (1);
}

int	backtracking(t_tetri **blocs, t_list **matrix, int **solution, int depth)
{
	t_list	*tmp;

	if (depth >= blocs[0]->length)
		return (1);
	tmp = NULL;
	tmp = matrix[depth];
	while (tmp != NULL)
	{
		if (depth == 0 || next_fits(solution, tmp->content, depth) == 1)
		{
			solution[depth] = malloc(5 * sizeof(int));
			solution[depth][4] = '\0';
			solution[depth][0] = ((int *)tmp->content)[0];
			solution[depth][1] = ((int *)tmp->content)[1];
			solution[depth][2] = ((int *)tmp->content)[2];
			solution[depth][3] = ((int *)tmp->content)[3];
			if ((backtracking(blocs, matrix, solution, depth + 1)) == 1)
				return (1);
			if (solution[depth])
				free(solution[depth]);
			solution[depth] = NULL;
		}
		tmp = tmp->next;
	}
	return (-1);
}
