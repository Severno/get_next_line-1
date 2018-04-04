/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:58 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:32:57 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

int		my_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!(n))
		return (0);
	n--;
	while(n && *s1 && *s1 == *s2)
	{
		n--;
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
