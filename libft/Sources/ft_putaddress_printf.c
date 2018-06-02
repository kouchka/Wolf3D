/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:11:03 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:46:12 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_field_address(t_pfspe *p)
{
	char c;

	ft_flags_zero(&c, p);
	(c == 'p' || (c == 'X' && p->diese > 0) || (c == 'x' && p->diese > 0)) ?
		p->field -= 2 : 0;
	while (p->field > 0)
	{
		ft_check_buffer(p, c);
		p->field--;
	}
}

static void		ft_preci_cpy_address(t_pfspe *p, char *str)
{
	int j;

	j = 0;
	while (p->precision > 0)
	{
		ft_check_buffer(p, '0');
		p->precision--;
	}
	while (str[j])
	{
		ft_check_buffer(p, str[j]);
		j++;
	}
}

static void		ft_checkflags_address(t_pfspe *p, char *str, char c)
{
	ft_calculate_address(p, str, c);
	if (p->minus > 0)
	{
		ft_adjustaddress(p, c, str);
		ft_preci_cpy_address(p, str);
		ft_field_address(p);
	}
	else if ((p->zero > 0 && p->diese > 0) || (c == 'p' && p->zero > 0))
	{
		ft_adjustaddress(p, c, str);
		ft_field_address(p);
		ft_preci_cpy_address(p, str);
	}
	else
	{
		ft_field_address(p);
		ft_adjustaddress(p, c, str);
		ft_preci_cpy_address(p, str);
	}
}

static void		ft_print(char *result, int compteur, char c, t_pfspe *point)
{
	int j;

	if (c == 'X')
	{
		j = compteur;
		while (result[j])
		{
			(result[j] >= 'a' && result[j] <= 'z') ?
				result[j] = ft_toupper(result[j]) : 0;
			j++;
		}
		ft_checkflags_address(point, result + compteur, c);
	}
	else
		ft_checkflags_address(point, result + compteur, c);
}

void			ft_putaddress_printf(void *addres, char c, t_pfspe *p, int base)
{
	unsigned long long int	nbr;
	int						compteur;
	char					*str;
	char					result[67];

	ft_typefor_address(p, addres, &nbr, c);
	compteur = 66;
	if (!ft_special_address(nbr, c, p))
		return ;
	str = "0123456789abcdefghijklmnopqrstuvwxyz";
	result[compteur] = '\0';
	while (nbr > 0)
	{
		compteur--;
		result[compteur] = str[nbr % base];
		nbr /= base;
	}
	ft_print(result, compteur, c, p);
}
