/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:49:17 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/23 17:06:28 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		z;
	size_t		s2_size;

	i = 0;
	z = 0;
	s2_size = 0;
	while (s2[s2_size])
		s2_size++;
	if (!s2_size)
		return ((char *)s1);
	while (s1[i] && i < n && s2_size < n - 1)
	{
		while (s2[z] == s1[i + z])
		{
			if (z == s2_size - 1)
				return ((char *)(s1 + i));
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}
