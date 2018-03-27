/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/03/27 17:54:02 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		refil_buf(char *buf, char *content)
{
	if (buf || content)
		;
	ft_putstr(buf);
}

static t_list	*get_fd_live(int fd, t_list **fd_history)
{
	t_list	*tmp;
	ft_putstr("3\n");

	tmp = *fd_history;
	ft_putstr("4\n");

	while (tmp)
	{
		ft_putstr("5\n");
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
		ft_putstr("6\n");
	}
		ft_putstr("7\n");
	tmp = ft_lstnew(NULL, fd);
		ft_putstr("8\n");
	tmp->next = *fd_history;
		ft_putstr("9\n");
	*fd_history = tmp;
		ft_putstr("10\n");
	return(tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				read_result;
	static t_list	*fd_history;
	t_list			*fd_live;

	ft_putstr("1\n");
	if (fd < 0 || line == NULL)
		return (-1);
	ft_putstr("2\n");
	fd_live = get_fd_live(fd, &fd_history);
	ft_putstr("5\n");
	refil_buf(buf, fd_live->content);

	str = ft_strnew(150);
	read_result = BUFF_SIZE + 1;

	ft_putstr("LOOP START\n");
	while(read_result >= BUFF_SIZE)
	{
		read_result = read(fd, buf, BUFF_SIZE);
		//if (!(read_result < BUFF_SIZE))
			str = ft_strjoin(str, buf);
		//else
		//	str = ft_strjoin(str, buf);
		//printf("Read result is %d\n", read_result);
	}
	ft_putstr("LOOP END\n");

	*line = str;
	return (0);
}
