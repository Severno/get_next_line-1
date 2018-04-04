/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:30:24 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"
char	*my_strchr(const char *s, int c)
{
	char	needle;
	size_t	i;

	needle = (char) c;
	i = 0;
	while (i <= my_strlen(s))
	{
		if (s[i] == needle)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
