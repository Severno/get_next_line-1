/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:38:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/02/01 19:31:42 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmy.h"

static int	my_isblank(char const *s, char c)
{
	int blank;

	blank = 1;
	while (*s)
	{
		if (*s != c)
			blank = 0;
		s++;
	}
	return (blank);
}

static void	my_newarraydelimstr(char **array, char const *s, char c)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (*s)
	{
		if (*s != c)
			j++;
		if (*s == c || *(s + 1) == '\0')
		{
			array[k] = my_strnew(j);
			k++;
			j = 0;
		}
		s++;
	}
	array[k] = NULL;
}

static char	**my_arraydelim(char const *s, char c)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	if(!(array = (char **) malloc((j + 2) * sizeof(char *))))
		return (NULL);
	my_newarraydelimstr(array, s, c);
	return (array);
}

static void	my_fillarraydelim(char **array, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			array[j][k] = s[i];
			k++;
		}
		if (s[i] == c)
		{
			j++;
			k = 0;
		}
		i++;
	}
}

char		**my_strsplit(char const *s, char c)
{
	char	*str_trim;
	char	*str_condensed;
	char	**array;

	array = NULL;
	if (my_isblank(s, c) != 0)
	{
		array = (char **) malloc(1 * sizeof(char *));
		array[0] = NULL;
		return (array);
	}
	str_trim = my_strtrimselect(s, c);
	str_condensed = my_removeselect(str_trim, c);
	array = my_arraydelim(str_condensed, c);
	my_fillarraydelim(array, str_condensed, c);
	return (array);
}
