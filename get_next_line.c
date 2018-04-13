/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/13 01:39:53 by dhojt            ###   ########.fr       */
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
		new[i] = c;
		free(line);
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
	free(tmp);
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

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				read_result;
	static t_list	*hist;
	t_list			*live;
	int				i;
	char			*tmp;//
	int				first;//

	first = 0;
	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 || !(*line = ft_strnew(1)) ||
			(!(live = get_live(fd, &hist))))
		return (-1);
	while ((read_result = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_result] = '\0';
		tmp = live->content;
		if (!(live->content = ft_strjoin(live->content, buf)))
			return (-1);
		if (first)
			free(tmp);
		first++;
		if (ft_strchr(buf, ENDL))
			break ;
	}
	if (!read_result && !ft_strlen(live->content))
		return (0);
	i = line_copy(line, live->content, ENDL);
	if (i < (int)ft_strlen(live->content))
	{
		tmp = live->content;
		live->content = ft_strdup(&((live->content) [i + 1]));
		free(tmp);
	}
	else
		ft_strclr(live->content);
	return (1);
}
