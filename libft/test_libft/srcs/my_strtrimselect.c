/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtrimselect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:29 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char	*my_strtrimselect(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = my_strlen(s) - 1;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[j] == c)
		j--;
	if (i > j)
	{
		if(!(str = my_strnew(1)))
			return (NULL);
	}
	else
	{
		if (!(str = my_strnew((j + 1) - i)))
			return (NULL);
		while (i <= j)
		{
			str[k] = s [i];
			i++;
			k++;
		}
	}
	return (str);
}
