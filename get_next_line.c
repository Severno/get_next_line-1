/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/05 15:52:01 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void			join_free(char *content, char *buf)
{
	char	*tmp;

	tmp = content;
	content = ft_strjoin(content, buf);
	free(tmp);
}

static void		split_new_line(char *content, char *str)
{
	char		*tmp;

	//SPLIT NEW LINE
	printf("***Split new line***\n");
	
	//IF CONTENT FAIL CHECK
	if (content)
	{


		printf(" 1\n");
		str = ft_strdup(content);
		
		
		printf(" 2\n");
		tmp = content;
		
		printf(" 3\n");
		str = ft_strdup(ft_strchr(content, ENDL) + 1);
		
		printf(" 4\n");
		free(tmp);
		
		printf(" 5\n");
		tmp = NULL;
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
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, fd);
	tmp->content = ft_strnew(BUFF_SIZE + 1);
	ft_lstadd(fd_history, tmp);
	//FD DISCOVERED
	printf("FD DISCOVERED\n");
	return(tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				read_result;
	static t_list	*fd_history;
	t_list			*fd_live;

	str = NULL;
	read_result = 0;

	//HANDLE FAILS && DISCOVER FD
	printf("HANDLE FAILS\n");	
	printf("DISCOVER FD\n");	
	if ((fd < 0 || line == NULL) || (!(fd_live = get_fd_live(fd, &fd_history))))
		return (-1);


	//IDENTIFY IF CONTENT HAS \n
	printf("IDENTIFY IF CONTENT HAS \\n\n");
	if (!(ft_strchr(fd_live->content, ENDL)))
	{


		while ((read_result = read(fd, buf, BUFF_SIZE)) > 0)
		{
		//READ FROM BUFFER
		printf("READ FROM BUFFER\n");

			//BUFFER READ INFO
			printf("Read %d characters reading: %s\n\n", read_result, buf);

			//DOES THE READING FAIL?
			printf("DOES TH READING FAIL?\n");
			if (read_result < 0)
				return -1;


			//DID THE BUFFER READ A \n?
			printf("DID THE BUFFER READ A \\n");
			if (ft_strchr(buf, '\n' || read_result < 0))
			{
				//YES
				printf(" YES\n");
				break ;
			}
			//NO
			printf(" NO\n");

			//JOIN BUF TO CONTENT
			printf("JOIN BUF TO CONTENT\n");
			join_free(fd_live->content, buf);
		}
	}
	//JOIN BUF TO FD LIVE FINAL
	printf("JOIN BUF TO FD LIVE FINAL\n");
	split_new_line(fd_live->content, str);
	return (0);
}
