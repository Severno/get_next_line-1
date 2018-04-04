/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:35:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:29:03 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

void	my_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst->next != NULL)
	{
		my_lstiter(lst->next, f);
		f(lst);
	}
	else
		f(lst);
}
