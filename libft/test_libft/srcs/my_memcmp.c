/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:36:27 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:29:24 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

int		my_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *str_s1;
	unsigned char *str_s2;

	i = 0;
	str_s1 = (unsigned char *) s1;
	str_s2 = (unsigned char *) s2;

	if (!(n))
		return (0);
	n--;
	while(n && *str_s1 && *str_s1 == *str_s2)
	{
		n--;
		str_s1++;
		str_s2++;
	}
	return ((unsigned char) *str_s1 - (unsigned char) *str_s2);
}
