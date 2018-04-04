/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:56 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:19 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char	*my_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char *start;

	start = s1;
	while (*s1)
		s1++;
	while (*s2 && n)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';

	return (start);
}
