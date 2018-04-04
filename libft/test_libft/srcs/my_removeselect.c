/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_removeselect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:36:56 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:30:00 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char	*my_removeselect(const char *s, char c)
{
	int		i;
	int 	j;
	char	*str;

	i = 0;
	j = 0;
	str = my_strnew(my_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] == s[i - 1])
			i++;
		
		if (!(s[i] == c && s[i] == s[i - 1]))
		{
			str[j] = s[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}
