/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfCS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:34:33 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:45:51 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_part_three(int32_t ca, t_pfspe *point)
{
	char str[4];

	str[3] = 0x80 + (ca % 64);
	ca /= 64;
	str[2] = 0x80 + (ca % 64);
	ca /= 64;
	str[1] = 0x80 + (ca % 64);
	ca /= 64;
	str[0] = 0xF0 + (ca % 8);
	ca = 0;
	while (ca < 4)
	{
		ft_check_buffer(point, str[ca]);
		ca++;
	}
}

static void		ft_part_two(int32_t ca, t_pfspe *point)
{
	char str[3];

	str[2] = 0x80 + (ca % 64);
	ca /= 64;
	str[1] = 0x80 + (ca % 64);
	ca /= 64;
	str[0] = 0xE0 + (ca % 16);
	ca = 0;
	while (ca < 3)
	{
		ft_check_buffer(point, str[ca]);
		ca++;
	}
}

static void		ft_part_one(int32_t ca, t_pfspe *point)
{
	char str[2];

	str[1] = 0x80 + (ca % 64);
	ca /= 64;
	str[0] = 0xC0 + (ca % 32);
	ca = 0;
	while (ca < 2)
	{
		ft_check_buffer(point, str[ca]);
		ca++;
	}
}

void			ft_printfcmaj(t_pfspe *point, int32_t ca)
{
	if (ca >= 0 && ca <= 127)
		ft_check_buffer(point, (char)ca);
	else if (ca >= 128 && ca <= 2047)
		ft_part_one(ca, point);
	else if (ca >= 2048 && ca <= 65535)
		ft_part_two(ca, point);
	else if (ca >= 65536 && ca <= 2097151)
		ft_part_three(ca, point);
}

void			ft_printfsmaj(t_pfspe *point, void *address)
{
	int32_t	*str;
	int		i;

	if (address == NULL)
	{
		ft_putstr_printf("(null)", point);
		return ;
	}
	str = (int32_t*)address;
	i = 0;
	while (str[i])
	{
		ft_printfcmaj(point, str[i]);
		i++;
	}
}
