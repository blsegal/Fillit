/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 22:00:24 by tmilon            #+#    #+#             */
/*   Updated: 2017/12/22 22:05:54 by tmilon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug_print_list(t_list **toprint, char *name)
{
	t_list	*matrix;
	int		i;

	matrix = *toprint;
	ft_putstr("|| Start of ");
	ft_putstr(name);
	ft_putstr("||\n");
	while (matrix != NULL)
	{
		while (((int*)matrix->content)[i])
		{
			ft_putnbr(((int *)matrix->content)[i++]);
			ft_putstr(" | ");
		}
		ft_putchar('\n');
		matrix = matrix->next;
	}
	ft_putstr("||  End  ||\n");
}
