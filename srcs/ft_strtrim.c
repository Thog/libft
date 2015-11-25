/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:53:46 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/25 09:30:21 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	char	*buf;
	long	index;

	while (is_whitespace(*s))
		s++;
	buf = ft_strchr(s, '\0') - 1;
	while (is_whitespace(*buf))
		buf--;
	index = buf - s + 1;
	if (index < 0)
		return (ft_strdup(""));
	return (ft_strsub(s, 0, index));
}
