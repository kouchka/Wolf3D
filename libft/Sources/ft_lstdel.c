/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 06:21:49 by allallem          #+#    #+#             */
/*   Updated: 2017/11/25 09:19:55 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *point;
	t_list *nextlist;

	point = *alst;
	while (point)
	{
		nextlist = point->next;
		(*del)(point->content, point->content_size);
		free(point);
		point = nextlist;
	}
	point = NULL;
	*alst = NULL;
}
