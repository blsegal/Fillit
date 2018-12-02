/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blsegal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:04:16 by tmilon            #+#    #+#             */
/*   Updated: 2018/12/02 18:03:49 by blsegal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# include "libft/libft.h"

typedef struct	s_tetri
{
	int			length;
	char		tab[20];
	int			width;
	int			height;
	int			wadjust[4];
	int			hadjust[4];
	int			isvalid;
}				t_tetri;

char			*read_file(char *file);

int				initmatrix(t_list **matrix, t_tetri *blocs, int max);

int				backtracking(t_tetri **blocs, t_list **matrix, int **solution,
				int depth);

void			ft_abort(char *str);

void			ft_replace(t_tetri *lst);

void			ft_check_lst(t_tetri *lst);

t_tetri			*ft_fill_lst(char *str);

void			ft_get_file(char **buf, char *file);

void			free_node(void *d, size_t n);

t_tetri			*ft_alloc(t_tetri *lst, char *buf);

void			ft_check_nbdiese(t_tetri *lst);

int				count_tetri(t_tetri *lst);

void			debug_print_list(t_list **toprint, char *name);

void			ft_setadj(t_tetri *lst);

void			ft_width(t_tetri *lst);

void			ft_height(t_tetri *lst, int nb, int nb2);

#endif
