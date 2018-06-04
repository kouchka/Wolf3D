/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typefor_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:51:24 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:47:12 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_special_address(unsigned long long int n, char c, t_pfspe *p)
{
	if (n == 0 && p->field <= 0 && p->precision <= 0 && c != 'p')
	{
		(p->point == 0 || ((c == 'o' || c == 'O') &&
		(p->point == 0 || p->diese > 0))) ? ft_check_buffer(p, '0') : 0;
		return (0);
	}
	return (1);
}

void	ft_calculate_address(t_pfspe *p, char *str, char c)
{
	if (p->precision > ft_strlen_longlong(str))
		p->field -= p->precision;
	else
		p->field -= ft_strlen_longlong(str);
	p->precision -= ft_strlen_longlong(str);
	(c == 'p' || (c == 'X' && p->diese > 0) || (c == 'x' && p->diese > 0))
		? p->field -= 2 : 0;
	if (c == 'o' && p->diese > 0 && p->precision > 1 && p->field <= 0)
		p->precision--;
	else if (c == 'o' && p->diese > 0 && p->point == 0)
		p->field--;
	(c == 'p' && ft_atoi_longlongint(str) == 0 && p->point == 0) ? p->field--
		: 0;
}

void	ft_adjustaddress(t_pfspe *p, char c, char *str)
{
	if (c == 'p' || (c == 'X' && p->diese > 0) || (c == 'x' && p->diese > 0))
	{
		ft_check_buffer(p, '0');
		if (c == 'X')
			ft_check_buffer(p, 'X');
		else
		{
			ft_check_buffer(p, 'x');
			(c == 'p' && ft_atoi_longlongint(str) == 0 && p->point == 0) ?
				ft_check_buffer(p, '0') : 0;
		}
	}
	else if ((c == 'o' || c == 'O') && p->diese > 0)
		ft_check_buffer(p, '0');
}

void	ft_typefor_address(t_pfspe *point, void *address,
		unsigned long long int *nbr, char c)
{
	if (c == 'p' || point->l == 1 || c == 'O' || c == 'U')
		*nbr = (unsigned long int)address;
	else if (point->l == 2 || c == 'b')
		*nbr = (unsigned long long int)address;
	else if (point->h == 1)
		*nbr = (unsigned short)address;
	else if (point->h == 2)
		*nbr = (unsigned char)address;
	else if (point->j)
		*nbr = (uintmax_t)address;
	else if (point->z)
		*nbr = (size_t)address;
	else
		*nbr = (unsigned int)address;
}
