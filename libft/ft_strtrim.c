/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:27 by dhojt             #+#    #+#             */
/*   Updated: 2018/01/30 16:03:47 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
			j--;
	if (i == ft_strlen(s))
	{
		if(!(str = ft_strnew(0)))
			return (NULL);
	}
	else
	{
		if(!(str = ft_strnew((j + 1) - i)))
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
