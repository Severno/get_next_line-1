/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:48 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:01 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

size_t	my_strlcpy(char * restrict dst, const char * restrict src, size_t size)
{
	size_t i;

	i = 0;
	if (size)
	{
	size--;
	while (src[i] != '\0' && size)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	}
	return (my_strlen(src));
}
