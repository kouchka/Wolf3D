/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:47:32 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:42:41 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_copy_in_buffer(t_pfspe *point, char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		ft_check_buffer(point, content[i]);
		i++;
	}
}

void			ft_flags_zero(char *c, t_pfspe *point)
{
	(point->zero > 0 && point->minus == 0 && point->precision <= 0) ? *c = '0'
		: (*c = ' ');
}

void			ft_puts_field(t_pfspe *point, char c)
{
	while (point->field > 0)
	{
		ft_check_buffer(point, c);
		point->field--;
	}
}

static	void	ft_puts_precision(t_pfspe *point, char *content)
{
	int i;

	i = 0;
	if (content != NULL)
	{
		while (point->precision > 0 && content[i])
		{
			ft_check_buffer(point, content[i]);
			point->precision--;
			i++;
		}
	}
}

void			ft_printfs(t_pfspe *point, char *content)
{
	char c;

	if (content == NULL)
	{
		ft_printfs(point, "(null)");
		return ;
	}
	if (point->point == 0 || point->precision > ft_strlen_longlong(content))
		point->field = point->field - ft_strlen_longlong(content);
	else
		point->field = point->field - point->precision;
	ft_flags_zero(&c, point);
	if (point->minus > 0)
	{
		(point->point > 0) ? ft_puts_precision(point, content) :
							ft_copy_in_buffer(point, content);
		ft_puts_field(point, c);
	}
	else
	{
		ft_puts_field(point, c);
		(point->point > 0) ? ft_puts_precision(point, content) :
						ft_copy_in_buffer(point, content);
	}
}
