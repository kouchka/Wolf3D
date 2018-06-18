/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:31:38 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:43:39 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_starflag_change(t_pfspe *p, int b)
{
	int nbr;

	nbr = va_arg(p->ap, int);
	if (nbr < 0 && b == 1)
	{
		p->minus++;
		nbr = nbr * -1;
	}
	else if (nbr < 0 && b == 0)
	{
		p->point = 0;
		return ;
	}
	(b == 0) ? p->precision = (long long int)nbr : 0;
	(b == 1) ? p->field = (long long int)nbr : 0;
}

int			ft_starflag_field(t_pfspe *p, char const *str, int *i)
{
	if (str[*i] == '*')
	{
		if (str[*i] == '*')
			*i = *i + 1;
		ft_starflag_change(p, 1);
		return (1);
	}
	return (0);
}

int			ft_starflag(t_pfspe *p, char const *str, int *i)
{
	int	star;

	star = 0;
	if (str[*i] == '.')
	{
		*i = *i + 1;
		p->point++;
		p->precision = 0;
		while (str[*i] == '*')
		{
			star++;
			*i = *i + 1;
		}
		while (ft_strstr_int("0123456789", str[*i]) && str[*i] != '\0')
		{
			p->precision = (p->precision * 10) + (str[*i] - 48);
			*i = *i + 1;
		}
		star >= 1 ? ft_starflag_change(p, 0) : 0;
		return (1);
	}
	else if (ft_starflag_field(p, str, i))
		return (1);
	return (0);
}
