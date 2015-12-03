/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:53:41 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/24 08:53:44 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *result;

	result = NULL;
	if (!s)
		return (result);
	while (*s)
	{
		if (*s == c)
			result = (char*)s;
		s++;
	}
	if (!c)
		result = (char*)s;
	return (result);
}
