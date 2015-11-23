/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:46:54 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/23 13:16:30 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int			i;
	size_t		dst_size;

	i = 0;
	dst_size = 0;
	while (dst[dst_size])
		dst_size++;
	while (src[i])
	{
		if (dst_size < size - 1)
			dst[dst_size] = src[i];
		dst_size++;
		i++;
	}
	dst[dst_size - 1] = '\0';
	return (dst_size);
}
