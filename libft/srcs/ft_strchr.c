/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/15 11:50:45 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	needle;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	needle = (char)c;
	i = 0;
	while (i <= len)
	{
		if (s[i] == needle)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
