/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 03:24:39 by allallem          #+#    #+#             */
/*   Updated: 2018/06/15 05:11:26 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_put_pixel(t_wolf3d *p, int x, int color)
{
	if (x < 0 || x > (WIN_X * WIN_Y) * 4)
		return ;
	if (x % 4 != 0)
		x -= x % 4;
	p->image.data[x] = color & 0xFF;
	p->image.data[x + 1] = color >> 8 & 0xFF;
	p->image.data[x + 2] = color >> 16 & 0xFF;
	p->image.data[x + 3] = color >> 24 & 0xFF;
}

int			ft_interpolate(int color, unsigned char *c, float tp)
{
	int temporaire;
	int temporaire2;
	int result;

	temporaire = color & 0xFF;
	temporaire2 = c[2] & 0xFF;
	result = (temporaire * tp) + (1 - tp) * temporaire2;
	result = result << 8;
	temporaire = color >> 8 & 0xFF;
	temporaire2 = c[1] & 0xFF;
	result += (temporaire * tp) + (1 - tp) * temporaire2;
	result = result << 8;
	temporaire = color >> 16 & 0xFF;
	temporaire2 = c[0] & 0xFF;
	result += (temporaire * tp) + (1 - tp) * temporaire2;
	return (result);
}
