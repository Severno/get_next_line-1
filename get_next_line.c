/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/05 09:31:10 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_list	*get_fd_live(int fd, t_list **fd_history)
{
	t_list	*tmp;

	if (!fd_history)
		return (NULL);
	tmp = *fd_history;

	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, fd);
	tmp->content = ft_strnew(BUFF_SIZE + 1);
	ft_lstadd(fd_history, tmp);
	return(tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*str;
	char			*tmp;
	int				read_result;
	static t_list	*fd_history;
	t_list			*fd_live;

	read_result = 0;
	if ((fd < 0 || line == NULL) || (!(fd_live = get_fd_live(fd, &fd_history))))
		return (-1);
	if (!(ft_strchr(fd_live->content, ENDL)))
	{
		while ((read_result = read(fd, buf, BUFF_SIZE)))
		{
			if (read_result < 0)
				return -1;
			read_result = read(fd, buf, BUFF_SIZE);
			tmp = fd_live->content;
			fd_live->content = ft_strjoin(fd_live->content, buf);
			if (ft_strchr(fd_live->content, '\n'))
				break ;
		}
	}
	fd_liveft_strsplitfirst(fd_live->content, ENDL)
	return (0);
}
