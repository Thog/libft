/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:44:50 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/25 15:22:54 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		set(int *a, int *b, int new_a, int new_b)
{
	*a = new_a;
	*b = new_b;
}

static void		ft_setintchar(char **a, int *b, char *new_a, int new_b)
{
	*a = new_a;
	*b = new_b;
}

static void		ft_init(int *n, int *sign, int *exp, int *size)
{
	set(exp, size, 1, 0);
	*sign = *n < 0 ? 1 : 0;
	*n *= *sign ? -1 : 1;
	while (*n >= *exp && *n < MAX)
		set(exp, size, *exp * 10, *size + 1);
	*exp = *n ? *exp / 10 : *exp;
	*size += (*sign || !*n) ? 1 : 0;
}

char			*ft_itoa(int n)
{
	int		exp;
	int		size;
	int		sign;
	float	i;
	char	*result;

	ft_init(&n, &sign, &exp, &size);
	if (!(result = (n == MIN ? ft_strdup("-2147483648") :
					ft_strnew(size + 1)))
			|| (result && n == MIN)
			|| !(result = n == MAX ? ft_strdup("2147483647") : result)
			|| (result && n == MAX))
		return (result);
	result[size] = '\0';
	if (sign)
		*result++ = '-';
	while (exp >= 1)
	{
		i = (n / exp);
		set((int *)result, &n, i + '0', n - i * exp);
		ft_setintchar(&result, &exp, result + 1, exp / 10);
	}
	return (result - size);
}
