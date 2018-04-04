/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:36:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:29:14 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

static t_list	**my_lstdelim(t_list **head, char *s, char c, int i, int j)
{
	t_list	*lst;
	t_list	*start;
	int		first;

	first = 0;
	while (s[i] != '\0' || s[i - 1] != '\0')
	{
		j = (!(s[i] == c)) ? (j += 1) : (j += 0);
		i = (s[i + 1] == '\0') ? (i += 1) : (i += 0);
		if (s[i] == c || s[i] == '\0')
		{
			if (first++ == 0)
			{
				if(!(lst = my_lstnew(my_strndup(s + (i - j), j), j + 1)))
					return (NULL);
				start = lst;
			}
			else
			{
				if(!(lst->next = my_lstnew(my_strndup(s + (i - j), j), j + 1)))
					return (NULL);
				lst = lst->next;
			}
			j = 0;
		}
		i++;
	}
	return (head = &start);
}

t_list			**my_lststrsplit(char const *s, char c)
{	
	char	*trimmed;
	char	*removed;
	t_list	**head;
	int i;
	int j;

	i = 0;
	j = 0;
	head = NULL;
	trimmed = my_strtrimselect(s, c);
	removed = my_removeselect(trimmed, c);
	head = my_lstdelim(head, removed, c, i, j);
	return (head);
}
