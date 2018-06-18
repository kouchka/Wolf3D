/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdi_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:49:59 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:42:54 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_precision(t_pfspe *point)
{
	while (point->precision > 0)
	{
		ft_check_buffer(point, '0');
		point->precision--;
		point->field--;
	}
}

void	ft_put_field(t_pfspe *point, char c, long long int content)
{
	(point->point > 0 && point->precision > 0) ?
		point->field = point->field - point->precision : 0;
	(point->space > 0 && point->plus <= 0 && content > 0) ? point->field--
		: 0;
	while (point->field > 0)
	{
		ft_check_buffer(point, c);
		point->field--;
	}
}

void	ft_flag_zero(t_pfspe *p, char *c)
{
	if (p->zero > 0 && p->precision <= 0 && p->point <= 0 && p->minus == 0)
		*c = '0';
	else
		(*c = ' ');
}

void	ft_flag_plus_space(t_pfspe *point, long long int content)
{
	if (point->plus > 0 && content > -1)
	{
		ft_check_buffer(point, '+');
		point->field--;
	}
	if (point->space > 0 && content > -1 && point->plus == 0)
	{
		ft_check_buffer(point, ' ');
		point->field--;
		point->space = 0;
	}
}
