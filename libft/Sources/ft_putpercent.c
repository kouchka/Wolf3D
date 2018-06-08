/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:10:49 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:43:09 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fieldpercent(t_pfspe *point, char c)
{
	while (point->field > 0)
	{
		ft_check_buffer(point, c);
		point->field--;
	}
}

void		ft_putpercent(t_pfspe *point)
{
	char c;

	c = ' ';
	point->precision = 0;
	point->point = 0;
	point->field -= 1;
	if (point->minus > 0)
	{
		ft_check_buffer(point, '%');
		ft_fieldpercent(point, c);
	}
	else
	{
		ft_flag_zero(point, &c);
		ft_fieldpercent(point, c);
		ft_check_buffer(point, '%');
	}
}
