/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:07:45 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/24 09:25:57 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;
	unsigned char	target;
	size_t			i;

	str = (const char *)s;
	target = (unsigned char)c;
	i = 0;
	if (!str)
		return (NULL);
	while (i < n)
	{
		if (str[i] == c)
			return (void *)(str + i);
		i++;
	}
	return (NULL);
}