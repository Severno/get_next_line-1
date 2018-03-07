/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:48 by dhojt             #+#    #+#             */
/*   Updated: 2018/01/30 23:48:09 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t size)
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
	return (ft_strlen(src));
}
