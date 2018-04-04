/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:13 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:34 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char	*my_strnew(size_t size)
{
	char *start;

	start = (char *) malloc((size + 1) * sizeof(*start));
	if (!start)
		return (NULL);
	my_bzero(start, size + 1);
	return (start);
}
