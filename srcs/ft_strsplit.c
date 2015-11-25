/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:59:45 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/25 15:11:37 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *str, char separator)
{
	size_t	i;
	size_t	index;
	int		l;

	i = 0;
	index = 0;
	l = 1;
	while (str[index])
	{
		if (str[index] == separator)
			l = 1;
		else if (l)
		{
			l = 0;
			i++;
		}
		index++;
	}
	return (i);
}

static char		*trim(const char *s, char c)
{
	char	*buf;
	long	index;

	while (*s == c)
		s++;
	buf = ft_strchr(s, '\0') - 1;
	while (*buf == c)
		buf--;
	index = buf - s + 1;
	if (index < 0)
		return (ft_strdup(""));
	return (ft_strsub(s, 0, index));
}

char			**ft_strsplit(char const *s, char c)
{
	int			start;
	int			l;
	size_t		i;
	char const	*tmp;
	char		**result;

	l = 1;
	i = 0;
	tmp = s;
	start = 0;
	result = (char **)malloc(sizeof(char*) * (count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	while (*tmp++ && count_words(s, c) != 1)
	{
		if (*tmp == c && !l && ((l = 1) + 1))
			result[i++] = ft_strsub(s, start, (tmp - s) - start);
		else if (*tmp != c && l && ((l = 0) + 1))
			start = tmp - s;
	}
	if (count_words(s, c) == 1)
		result[i++] = ft_strdup(trim(s, c));
	result[i] = NULL;
	return (result);
}
