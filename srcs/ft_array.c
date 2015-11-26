/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:17:46 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/26 17:40:33 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array			*array_new(size_t type_size)
{
	t_array		*result;

	result = (t_array *)malloc(sizeof(t_array));
	if (result == NULL)
		return (NULL);
	result->data = (t_arrayelem **)malloc(sizeof(t_arrayelem));
	if (result->data == NULL)
		return (NULL);
	result->size = 0;
	result->index = 0;
	result->type_size = type_size;
	result->it_cursor = 0;
	result->data[0] = NULL;
	return (result);
}

void			array_destroy(t_array **array)
{
	if (array != NULL)
	{
		free((*array)->data);
		(*array)->data = NULL;
		free(array);
		*array = NULL;
	}
}

int				array_resize(t_array *array, size_t size)
{
	t_arrayelem		**data;
	t_arrayelem		**ptr;
	size_t			index;

	ptr = array->data;
	index = 0;
	if (array != NULL)
	{
		data = (t_arrayelem **)malloc(sizeof(t_arrayelem) * (size + 1));
		if (data == NULL)
			return (0);
		while (index < size && ((size_t)(ptr - array->data)) < size)
		{
			*data = ptr[index++];
			data++;
		}
		data[size] = NULL;
		free(array->data);
		array->data = data;
		return (1);
	}
	return (0);
}

int				array_push(t_array *array, void *elem)
{
	if (array != NULL)
	{
		if (array->size < (array->index + 1) &&
				!array_resize(array, array->index + 1))
		{
			return (0);
		}
		array->data[array->index++] = elem;
		return (1);
	}
	return (0);
}
