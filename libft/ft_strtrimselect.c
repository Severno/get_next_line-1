/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimselect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:29 by dhojt             #+#    #+#             */
/*   Updated: 2018/01/31 16:29:01 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimselect(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[j] == c)
		j--;
	if (i > j)
	{
		if(!(str = ft_strnew(1)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strnew((j + 1) - i)))
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
