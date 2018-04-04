/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:46 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:30:58 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

size_t	my_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (my_strlen(dst) < dstsize) ? my_strlen(dst) : dstsize;
	len += my_strlen(src);
	if (dstsize)
	{
		while (*dst)
		{
			dst++;
			i++;
		}
		while (*src && i < (dstsize - 1))
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (len);
}
