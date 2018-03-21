/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/03/08 11:48:55 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	char	*str;
	char	buf[BUFF_SIZE + 1];
	int		read_result;

	str = ft_strnew(150);
	read_result = BUFF_SIZE + 1;
	
	ft_putstr("LOOP START\n");
	while(read_result >= BUFF_SIZE)
	{
		read_result = read(fd, buf, BUFF_SIZE);
		if (!(read_result < BUFF_SIZE))
			str = ft_strjoin(str, buf);
		else
			str = ft_strjoin(str, buf);
		printf("Read result is %d\n", read_result);

	}
	ft_putstr("LOOP END\n");

	*line = str;
	return (0);
}
