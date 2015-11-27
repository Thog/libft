/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:53:39 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/27 15:47:20 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s || !(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result = ft_strncpy(result, (s + start), len);
	result[len] = '\0';
	return (result);
}
