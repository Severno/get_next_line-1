/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/13 15:48:08 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_join(char *line, char c)
{
	int		i;
	int		len;
	char	*new;
	char	*tmp;

	i = 0;
	if (line && c)
	{
		tmp = line;
		len = ft_strlen(line);
		if (!(new = ft_strnew(len + 1)))
			return (NULL);
		while (i < len)
		{
			new[i] = line[i];
			i++;
		}
		free(line);
		new[i] = c;
		return (new);
	}
	return (NULL);
}

int		line_copy(char **line, char *content, char c)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strnew(i)))
		return (0);
	while (content[j] && j < i)
	{
		if (!(*line = line_join(*line, content[j])))
			return (0);
		j++;
	}
	return (i);
}

t_list	*get_live(int fd, t_list **hist)
{
	t_list	*tmp;

	if (!hist)
		return (NULL);
	tmp = *hist;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(hist, tmp);
	return (tmp);
}

int		my_read(const int fd, char **content)
{
	int		(read_result);
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((read_result = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_result] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, ENDL))
			break ;
	}
	return (read_result);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			read_result;
	static t_list	*hist;
	t_list			*live;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 ||
			(!(live = get_live(fd, &hist))))
		return (-1);
	tmp = live->content;
	read_result = my_read(fd, &tmp);
	live->content = tmp;
	if (!read_result && !ft_strlen(live->content))
		return (0);
	read_result = line_copy(line, live->content, ENDL);
	if (read_result < ft_strlen(live->content))
	{
		tmp = live->content;
		live->content = ft_strdup(&((live->content)[read_result + 1]));
		free(tmp);
	}
	else
		ft_strclr(live->content);
	return (1);
}
