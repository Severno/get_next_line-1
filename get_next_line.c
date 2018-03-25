/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/03/25 15:42:03 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_list	*get_fd_live(int fd, t_list **fd_history)
{
	t_list	*tmp;

	tmp = *fd_history;

	while (fd_history)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, fd);
	tmp->next = *fd_history;
	*fd_history = tmp;
	return(tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				read_result;
	static t_list	*fd_history;
	t_list			*fd_live;

	if (fd < 0 || line == NULL)
		return (-1);
	fd_live = get_fd_live(fd, &fd_history);

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
