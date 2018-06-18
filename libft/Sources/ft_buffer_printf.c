/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:44:12 by allallem          #+#    #+#             */
/*   Updated: 2018/02/01 18:14:24 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pull_all(t_pfspe *point)
{
	write(1, point->contenu, point->cursor);
	point->value = point->value + point->cursor;
}

void	ft_check_buffer(t_pfspe *point, char c)
{
	if (point->cursor == B_PF_SIZE)
	{
		write(1, point->contenu, B_PF_SIZE);
		point->cursor = 0;
		point->value = point->value + (B_PF_SIZE);
	}
	point->contenu[point->cursor++] = c;
}
