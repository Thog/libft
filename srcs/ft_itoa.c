/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:44:50 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/25 09:33:59 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		set(int *a, int *b, int a_val, int b_val)
{
	*a = a_val;
	*b = b_val;
}

static void		ft_setintchar(char **a, int *b, char *a_val, int b_val)
{
	*a = a_val;
	*b = b_val;
}

static void		ft_init(int *n, int *neg, int *exp, int *size)
{
	set(exp, size, 1, 0);
	*neg = *n < 0 ? 1 : 0;
	*n *= *neg ? -1 : 1;
	while (*n >= *exp && *n < MAX)
		set(exp, size, *exp * 10, *size + 1);
	*exp = *n ? *exp / 10 : *exp;
	*size += (*neg || !*n) ? 1 : 0;
}

char			*ft_itoa(int n)
{
	int		exp;
	int		size;
	int		neg;
	float	f;
	char	*result;

	ft_init(&n, &neg, &exp, &size);
	if (!(result = (n == MIN ? ft_strdup("-2147483648") :
					(char *)malloc(sizeof(char) * (size + 1))))
			|| (result && n == MIN)
			|| !(result = n == MAX ? ft_strdup("2147483647") : result)
			|| (result && n == MAX))
		return (result);
	result[size] = '\0';
	if (neg)
		*result++ = '-';
	while (exp >= 1)
	{
		f = (float)(n / exp);
		set((int *)result, &n, ((int)f) + '0', n - ((int)f) * exp);
		ft_setintchar(&result, &exp, result + 1, exp / 10);
	}
	return (result - size);
}
