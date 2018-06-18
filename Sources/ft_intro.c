/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 01:32:08 by allallem          #+#    #+#             */
/*   Updated: 2018/06/14 03:21:33 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_swap_color(t_wolf3d *p, int i)
{
	int				j;
	int				k;
	unsigned char	*c;

	j = 0;
	while (j < WIN_Y)
	{
		k = 0;
		while (k < WIN_X)
		{
			c = &p->tex_i[INTRO_T].data[((int)((float)j / WIN_Y *
	p->tex_i[INTRO_T].hei) * p->tex_i[INTRO_T].size_line)
	+ ((int)((float)k / WIN_X * p->tex_i[INTRO_T].wid) * 4)];
			ft_put_pixel(p, (j * p->image.size_line) + (k * 4),
			ft_interpolate(0x000000, c, 1 - (i / 100.0)));
			k++;
		}
		j++;
	}
}

void			ft_intro(t_wolf3d *p)
{
	static int i;

	ft_swap_color(p, i);
	if (i == WAIT)
		p->event.intro = 1;
	i++;
}
