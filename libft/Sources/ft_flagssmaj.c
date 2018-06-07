/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagssmaj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:17:01 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:44:51 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_useflags_s(t_pfspe *p, int32_t *str)
{
	char	c;
	int		i;

	i = 0;
	ft_flags_zero(&c, p);
	if (p->minus > 0)
	{
		while (str[i])
		{
			ft_printfcmaj(p, str[i]);
			i++;
		}
		ft_puts_field(p, c);
	}
	else
	{
		ft_puts_field(p, c);
		while (str[i])
		{
			ft_printfcmaj(p, str[i]);
			i++;
		}
	}
}

static int			ft_adjustfield_s(int32_t ca)
{
	if (ca >= 0 && ca <= 127)
		return (-1);
	else if (ca >= 128 && ca <= 2047)
		return (-2);
	else if (ca >= 2048 && ca <= 65535)
		return (-3);
	else if (ca >= 65536 && ca <= 2097151)
		return (-4);
	return (0);
}

static void			ft_part_three(t_pfspe *p, int i, int j, int32_t *str)
{
	char c;

	ft_flags_zero(&c, p);
	if (p->minus > 0)
	{
		while (j < i)
		{
			ft_printfcmaj(p, str[j]);
			j++;
		}
		if (p->field > 0)
			ft_puts_field(p, c);
	}
	else
	{
		if (p->field > 0)
			ft_puts_field(p, c);
		while (j < i)
		{
			ft_printfcmaj(p, str[j]);
			j++;
		}
	}
}

static void			ft_part_two(t_pfspe *p, int32_t *str, int i, int n)
{
	int j;

	j = 0;
	(n > p->precision) ? i-- : 0;
	if (p->point > 0)
		ft_part_three(p, i, j, str);
	else
	{
		i = 0;
		while (str[i])
		{
			p->field += ft_adjustfield_s(str[i]);
			i++;
		}
		ft_useflags_s(p, str);
	}
}

void				ft_flagssmaj(t_pfspe *p, void *address)
{
	int		i;
	int		n;
	int32_t	*str;

	n = 0;
	i = 0;
	if (address == NULL)
	{
		ft_putstr_printf("(null)", p);
		return ;
	}
	str = (int32_t*)address;
	if (p->point > 0)
	{
		while (str[i] && n < p->precision)
		{
			n = n - ft_adjustfield_s(str[i]);
			i++;
		}
		(n > p->precision) ? p->field = p->field
		- n - ft_adjustfield_s(str[i - 1]) : (p->field -= p->precision);
	}
	ft_part_two(p, str, i, n);
}
