/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:41:51 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:45:58 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putspedi(t_pfspe *point, long long int ct, char c)
{
	if (point->minus > 0)
	{
		ft_flag_plus_space(point, ct);
		(ct < 0) ? ft_check_buffer(point, '-') : 0;
		ft_put_precision(point);
		ft_bufnbr_printf(ct, point);
		ft_put_field(point, c, ct);
	}
	else if (point->zero > 0 && point->field > 0)
	{
		ft_flag_plus_space(point, ct);
		(ct < 0) ? ft_check_buffer(point, '-') : 0;
		ft_put_field(point, c, ct);
		ft_put_precision(point);
		ft_bufnbr_printf(ct, point);
	}
}

static int		ft_use_flags(t_pfspe *point, long long int ct)
{
	char c;

	ft_flag_zero(point, &c);
	if (ct == 0 && point->precision <= 0 && point->point > 0)
	{
		ft_flag_plus_space(point, ct);
		point->field++;
		ft_put_field(point, c, ct);
	}
	else if (point->minus > 0 || (point->zero > 0 && point->field > 0))
		ft_putspedi(point, ct, c);
	else
	{
		if (point->plus > 0 && ct > 0)
			point->field--;
		ft_put_field(point, c, ct);
		ft_flag_plus_space(point, ct);
		(ct < 0) ? ft_check_buffer(point, '-') : 0;
		ft_put_precision(point);
		ft_bufnbr_printf(ct, point);
	}
	return (0);
}

int				ft_printfdi(char c, t_pfspe *point, long long int content)
{
	if (point->h == 1 && c != 'D')
		content = (short)content;
	else if (point->h == 2 && c != 'D')
		content = (char)content;
	else if (point->j == 1 && c != 'D')
		content = (intmax_t)content;
	else if (point->z == 1 && c != 'D')
		content = (size_t)content;
	else if (point->l == 1 && c != 'D')
		content = (long)content;
	else if (point->l == 2 && c != 'D')
		content = (long long int)content;
	else if (c != 'D')
		content = (int)content;
	point->precision = point->precision - ft_sizeoflonglongint(content, 1);
	point->field = point->field - ft_sizeoflonglongint(content, 0);
	ft_use_flags(point, content);
	return (point->result);
}
