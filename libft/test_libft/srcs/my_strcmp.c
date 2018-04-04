/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:37:29 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:30:32 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

int		my_strcmp(const char *s1, const char *s2)
{
	if (my_strlen(s1) > my_strlen(s2))
		return(my_strncmp(s1, s2, (my_strlen(s1))));
	return(my_strncmp(s1, s2, (my_strlen(s2))));
}
