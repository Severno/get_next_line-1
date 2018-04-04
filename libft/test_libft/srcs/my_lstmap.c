/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:36:08 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:29:06 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

t_list			*my_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*new;
	t_list	*tmp;

	tmp = f(lst);
	if (!(new = my_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	ptr = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new->next = my_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (ptr);
}
