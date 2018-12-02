/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blsegal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:19:04 by tmilon            #+#    #+#             */
/*   Updated: 2018/12/02 18:03:10 by blsegal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include "libft/libft.h"

void	ft_check_itsquare(char *buf, int y, int n)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			n++;
			if (buf[i - 1] == '\n' && buf[i - 2] == '\n')
				ft_abort("problem is square");
		}
		if (((i - y + 1) % 20 == 0 && n != 4 && i != 0) ||
				((i - y + 1) % 5 == 0 && buf[i] != '\n'))
			ft_abort("problem is square");
		if (buf[i] == '\n' && buf[i - 1] == '\n')
		{
			n = 0;
			y++;
		}
		i++;
	}
	if ((i - y) % 20 != 0 || (buf[i - 1] == '\n' && buf[i - 2] == '\n'))
		ft_abort("nope");
}

void	ft_check_file(char *buf)
{
	int		i;
	int		y;
	int		n;

	i = 0;
	y = 0;
	n = 0;
	while (buf[i])
	{
		if (buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			ft_abort("problem check file");
		i++;
	}
	if (ft_strlen(buf) >= 546)
		ft_abort("problem strlen");
	ft_check_itsquare(buf, y, n);
}

void	ft_get_file(char **buf, char *file)
{
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_abort("file");
	ret = read(fd, *buf, 550);
	if (ret == -1)
		ft_abort("file");
	ft_check_file(*buf);
	if (close(fd) == -1)
		ft_abort("file");
}
