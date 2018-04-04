/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:10 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:30:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char	*my_strcat(char *restrict s1, const char *restrict s2)
{
	char *start;

	start = s1;
	while (*s1)
		s1++;
	my_strcpy(s1, s2);
	return (start);
}
