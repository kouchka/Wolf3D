/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 07:25:51 by allallem          #+#    #+#             */
/*   Updated: 2017/11/25 08:46:09 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *init;
	t_list *nouveau;
	t_list *head;

	if (lst != NULL)
	{
		if (!(init = malloc(sizeof(t_list))))
			return (NULL);
		init->next = NULL;
		init = (*f)(lst);
		lst = lst->next;
		head = init;
	}
	while (lst != NULL)
	{
		if (!(nouveau = malloc(sizeof(t_list))))
			return (NULL);
		nouveau = (*f)(lst);
		init->next = nouveau;
		init = init->next;
		lst = lst->next;
	}
	return (head);
}
