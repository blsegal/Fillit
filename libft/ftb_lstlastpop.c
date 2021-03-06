/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftb_lstlastpop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:47:13 by tmilon            #+#    #+#             */
/*   Updated: 2017/12/23 11:21:22 by tmilon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../fillit.h"
#include <stdio.h>

void	ftb_lstlastpop(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (*alst == NULL)
		return ;
	tmp = *alst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	ft_lstdelone(&tmp, del);
	tmp = NULL;
}
