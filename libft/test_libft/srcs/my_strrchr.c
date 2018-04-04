/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:19 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:39 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"
char	*my_strrchr(const char *s, int c)
{
	char	needle;
	size_t	i;

	needle = (char) c;
	i = my_strlen(s) + 1;
	while (i > 0)
	{
		if (s[i - 1] == needle)
			return ((char *)s + (i - 1));
		i--;
	}
	return (NULL);
}
