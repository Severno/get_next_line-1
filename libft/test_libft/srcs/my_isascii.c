/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:35:19 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:28:32 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		my_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}