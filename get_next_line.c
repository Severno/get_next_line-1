/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/09 02:54:42 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char		*join_free(char *content, char *buf)
{
	char	*tmp;
	
	tmp = content;
	content = ft_strjoin(content, buf);
	free(tmp);
	return (content);
}

static void		split_new_line(char **content, char **str)
{
	if (content)
	{
		*str = ft_strdup(*content);
		*(ft_strchr(*str, ENDL)) = '\0';
			
		*content = ft_strdup(ft_strchr(*content, ENDL) + 1);
	}
}

static t_list	*get_fd_live(int fd, t_list **fd_history)
{
	t_list	*tmp;

	if (!fd_history)
		return (NULL);
	tmp = *fd_history;

	while (tmp)
	{
		if ((int)tmp->content_size == fd)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, fd);
	tmp->content = ft_strnew(1);
	tmp->content_size = fd;
	ft_lstadd(fd_history, tmp);
	return(tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				read_result;
	static t_list	*fd_history;
	t_list			*fd_live;
	int				ret;

	ret = 1;

	str = NULL;
	read_result = 0;

	if ((fd < 0 || line == NULL) || (!(fd_live = get_fd_live(fd, &fd_history))))
		return (-1);
	
	if (!(ft_strchr(fd_live->content, ENDL)))
	{


		while ((read_result = read(fd, buf, BUFF_SIZE)) > 0)
		{
			if (read_result < 0)
				return -1;
			if (ft_strchr(buf, '\n') || read_result < 0)
			{
				break ;
			}
			fd_live->content = join_free(fd_live->content, buf);

		}
	}
	fd_live->content = join_free(fd_live->content, buf);

	if (!read_result && !ft_strchr(fd_live->content, ENDL))
	{
		*line = ft_strdup(fd_live->content);
		return (0);
	}
	else
		split_new_line((char **)&fd_live->content, &str);
	*line = str;
	return (1);
}
