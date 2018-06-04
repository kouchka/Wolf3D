/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstruct_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:47:34 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:44:38 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_adjust_struct(t_pfspe *p)
{
	if (p->j > 0)
		reset_if_j(p);
	else if (p->l > 0)
		reset_if_l(p);
	else if (p->z > 0)
		reset_if_z(p);
	else if (p->h > 0)
	{
		if (p->h > 1)
			p->h = 2;
	}
}

static int			ft_field(t_pfspe *p, char const *str, int *i)
{
	if (ft_strstr_int("123456789", str[*i]) && str[*i] != '\0')
	{
		p->field = 0;
		while (ft_strstr_int("0123456789", str[*i]) && str[*i] != '\0')
		{
			p->field = (p->field * 10) + (str[*i] - 48);
			*i = *i + 1;
		}
		return (1);
	}
	return (0);
}

static int			ft_increment(t_pfspe *point, char const *str, int *i)
{
	if (str[*i] == 'j')
		point->j++;
	else if (str[*i] == 'z')
		point->z++;
	else if (str[*i] == 'l')
		point->l++;
	else if (str[*i] == 'h')
		point->h++;
	else if (ft_starflag(point, str, i))
		return (1);
	if (ft_field(point, str, i))
		return (1);
	return (0);
}

static void			ft_increment_flags(t_pfspe *point, char c)
{
	if (c == '#')
		point->diese++;
	else if (c == '0')
		point->zero++;
	else if (c == ' ')
		point->space++;
	else if (c == '+')
		point->plus++;
	else if (c == '-')
		point->minus++;
}

int					ft_fillstruct_printf(t_pfspe *point, char const *str)
{
	int i;

	i = 0;
	while (ft_strstr_int("0 +*-# jlhz0123456789.", str[i]) && str[i] != '\0')
	{
		while (ft_strstr_int("0 +-#", str[i]) && str[i] != '\0')
		{
			ft_increment_flags(point, str[i]);
			i++;
		}
		while (ft_strstr_int("jlhz123456789.*", str[i]) && str[i] != '\0')
			(!ft_increment(point, str, &i)) ? i++ : 0;
	}
	ft_adjust_struct(point);
	point->result = i;
	return (i);
}
