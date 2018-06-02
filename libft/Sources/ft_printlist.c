/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 10:46:58 by allallem          #+#    #+#             */
/*   Updated: 2017/11/25 12:26:10 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist(t_list *list)
{
	while (list != NULL)
	{
		ft_putstr(list->content);
		ft_putchar('\n');
		list = list->next;
	}
}
