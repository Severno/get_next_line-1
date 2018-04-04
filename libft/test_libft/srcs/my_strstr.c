/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:22 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:45 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

char *my_strstr(const char *haystack, const char *needle)
{
	return(my_strnstr(haystack, needle, my_strlen(haystack)));
}
