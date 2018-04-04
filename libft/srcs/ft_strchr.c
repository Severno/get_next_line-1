/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/03 13:47:38 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	needle;
	size_t	i;

	needle = (char)c;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == needle)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
