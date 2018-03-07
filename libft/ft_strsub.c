/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:25 by dhojt             #+#    #+#             */
/*   Updated: 2018/01/27 15:38:26 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub_str;
	size_t i;

	i = 0;
	sub_str = ft_strnew(len);
	if (!sub_str)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	return (sub_str);
}
