/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 05:58:07 by allallem          #+#    #+#             */
/*   Updated: 2017/11/25 08:45:56 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*point;

	if (!(point = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		point->content = NULL;
		point->content_size = 0;
	}
	else
	{
		point->content = ft_strdup(content);
		point->content_size = content_size;
	}
	point->next = NULL;
	return (point);
}
