/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:41 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:30:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

void	my_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	i = 0;
	while (s[i])
		f(&s[i++]);
}