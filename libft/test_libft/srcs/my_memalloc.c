/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:36:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:29:17 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char	*my_memalloc(size_t size)
{
	char *start;

	start = malloc(size);
	if (!start)
		return (NULL);
	my_bzero(start, size);
	return (start);
}
