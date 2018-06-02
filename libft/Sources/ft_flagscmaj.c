/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagscsmaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:37:39 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:48:03 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_useflags(t_pfspe *p, int32_t address)
{
	char c;

	ft_flags_zero(&c, p);
	if (p->minus > 0)
	{
		ft_printfcmaj(p, address);
		ft_puts_field(p, c);
	}
	else
	{
		ft_puts_field(p, c);
		ft_printfcmaj(p, address);
	}
}

void		ft_flagscmaj(t_pfspe *p, int32_t ca)
{
	if (ca >= 0 && ca <= 127)
		p->field -= 1;
	else if (ca >= 128 && ca <= 2047)
		p->field -= 2;
	else if (ca >= 2048 && ca <= 65535)
		p->field -= 3;
	else if (ca >= 65536 && ca <= 2097151)
		p->field -= 4;
	ft_useflags(p, ca);
}
