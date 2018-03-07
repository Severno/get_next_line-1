/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:36:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/01/27 15:36:20 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	**ft_lstdelim(t_list **head, char *s, char c, int i, int j)
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
				if(!(lst = ft_lstnew(ft_strndup(s + (i - j), j), j + 1)))
					return (NULL);
				start = lst;
			}
			else
			{
				if(!(lst->next = ft_lstnew(ft_strndup(s + (i - j), j), j + 1)))
					return (NULL);
				lst = lst->next;
			}
			j = 0;
		}
		i++;
	}
	return (head = &start);
}

t_list			**ft_lststrsplit(char const *s, char c)
{	
	char	*trimmed;
	char	*removed;
	t_list	**head;
	int i;
	int j;

	i = 0;
	j = 0;
	head = NULL;
	trimmed = ft_strtrimselect(s, c);
	removed = ft_removeselect(trimmed, c);
	head = ft_lstdelim(head, removed, c, i, j);
	return (head);
}
