/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:03:38 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/26 12:24:02 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*cursor;
	t_list	*tmp;
	t_list	*prev;

	result = f(lst);
	if (result == NULL)
		return (NULL);
	result->next = NULL;
	prev = result;
	cursor = lst->next;
	while (cursor != NULL)
	{
		tmp = f(cursor);
		if (tmp == NULL)
			break ;
		prev->next = tmp;
		prev = tmp;
		cursor = cursor->next;
	}
	return (result);
}
