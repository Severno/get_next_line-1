/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:45 by dhojt             #+#    #+#             */
/*   Updated: 2018/04/03 19:54:32 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		join_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!join_str)
			return (NULL);
		while (j < ft_strlen(s1))
			join_str[i++] = s1[j++];
		j = 0;
		while (j < ft_strlen(s2))
		{
			join_str[i] = s2[j];
			i++;
			j++;
		}
		return (join_str);
	}
	return (NULL);
}
