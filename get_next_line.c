/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/05 14:35:40 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		split_new_line(char *content, char *str)
{


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

	//HANDLE FAILS && DISCOVER FD
	if ((fd < 0 || line == NULL) || (!(fd_live = get_fd_live(fd, &fd_history))))
		return (-1);


	//IDENTIFY IF CONTENT HAS \n
	if (!(ft_strchr(fd_live->content, ENDL)))
	{


		//READ FROM BUFFER
		while ((read_result = read(fd, buf, BUFF_SIZE)) > 0)
		{
			
			//DOES THE READING FAIL?
			if (read_result < 0)
				return -1;


			//DID THE BUFFER READ A \n?
			if (ft_strchr(buf, '\n' || read_result < 0))
				break ;


			//JOIN BUF TO FD LIVE
			str = JOIN(fd_live->content, buf);
		}
	}
	str = ft_strsplitfirst(fd_live->content, ENDL);
	return (0);
}
