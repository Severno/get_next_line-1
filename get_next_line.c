/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/11 09:07:44 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_strjoinch(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}*/

/*int			ft_strcopychr(char **dst, char *src, char c)
{
	int		i;
	int		count;
	int		pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoinch(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}*/

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

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				read_result;
	static t_list	*fd_history;
	t_list			*fd_live;
	int				ret;
	int				i;

	ret = 1;
	str = NULL;
	read_result = 0;

	if ((fd < 0 || line == NULL) || (!(fd_live = get_fd_live(fd, &fd_history))))
		return (-1);
	if (read(fd, buf, 0) < 0)
		return (-1);
	if(!(*line = ft_strnew(1)))
		return (-1);
	while ((read_result = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_result] = '\0';
		if (!(fd_live->content = ft_strjoin(fd_live->content, buf)))
			return (-1);;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_result < BUFF_SIZE && !ft_strlen(fd_live->content))
		return (0);
	i = ft_strcopychr(line, fd_live->content, '\n');
	if (i < (int)ft_strlen(fd_live->content))
		fd_live->content += (i + 1);
	else
		ft_strclr(fd_live->content);
	return (1);
}
