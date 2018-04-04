/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:27 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:49 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char	*my_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = my_strlen(s) - 1;
	k = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
			j--;
	if (i == my_strlen(s))
	{
		if(!(str = my_strnew(0)))
			return (NULL);
	}
	else
	{
		if(!(str = my_strnew((j + 1) - i)))
			return (NULL);
		while (i <= j)
		{
			str[k] = s[i];
			i++;
			k++;
		}
	}
	return (str);
}
