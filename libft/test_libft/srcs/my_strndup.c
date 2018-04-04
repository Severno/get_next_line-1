/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:01 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:30 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char	*my_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	len;
	size_t	size;
	int		trail_zero;

	len = my_strlen(s1);
	if (len < n)
		size = len;
	else
	{
		size = n;
		trail_zero = 1;
	}
	s2 = my_strnew(size);
	if (!s2)
		return (NULL);
	my_strncpy(s2, s1, size);
	if (trail_zero)
		s2[size] = '\0';
	return (s2);
}
