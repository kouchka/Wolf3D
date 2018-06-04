/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:19:59 by allallem          #+#    #+#             */
/*   Updated: 2018/06/04 17:53:56 by allallem         ###   ########.fr       */
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
}

void		ft_print_me(t_wolf3d *p)
{
	int i;
	int j;
	float y;
	int		check;

	i = 0;
	j = 0;
	while (i < (int)p->mini.xmap / 4)
	{
		j = 0;
		while (j < p->mini.xmap / 4)
		{
			y = p->image.size_line * ((p->cam.y * p->mini.ymap + p->mini.marge_y + i));
			if (fmod(y, p->image.size_line) != 0)
				y -= fmod(y, p->image.size_line);
			if ((check = y + (((p->cam.x * p->mini.xmap) + p->mini.marge_x + j) * 4)) / p->image.size_line == (y / p->image.size_line))
				ft_put_pixel(p, check, 0xFF0000);
			j++;
		}
		i++;
	}
}

void		ft_print_map(t_wolf3d *p)
{
	int i;
	int j;
	int loly;
	int lolx;
	int check;
	unsigned char *c;
	int color;
	int limitx;
	int limity;

	i = 0;
	p->mini.xmap = p->mini.size_x / p->map.x - 1;
	p->mini.ymap = p->mini.size_y / p->map.y;
	limitx = 0;
	limity = 0;
	while (p->mini.xmap * limitx < WIN_X && limitx < p->map.x)
		limitx++;
	while (p->mini.ymap * limity < WIN_Y && limity < p->map.y)
		limity++;
	while (i < limity)
	{
		j = 0;
		while (j < limitx)
		{
			if (p->map.map[i][j])
			{
				loly = 0;
				while (loly < p->mini.ymap)
				{
					lolx = 0;
					while (lolx < p->mini.xmap)
					{
						check = (((i * p->mini.ymap) + loly + p->mini.marge_y) * p->image.size_line) + ((j * p->mini.xmap) + p->mini.marge_x + lolx) * 4;
						if (check / p->image.size_line == (((i * p->mini.ymap) + loly + p->mini.marge_y)))
						{
							c = &p->tex_i[p->map.map[i][j]].data[(int)((p->tex_i[p->map.map[i][j]].hei * (loly / p->mini.ymap))
							+ (((p->tex_i[p->map.map[i][j]].wid * (lolx / p->mini.xmap))))) * 4];
							color = c[2] & 0xFF;
							color = color << 8;
							color += c[1] & 0xFF;
							color = color << 8;
							color += c[0] & 0xFF;
							ft_put_pixel(p, check, color);
						}
						lolx++;
					}
					loly++;
				}
			}
			j++;
		}
		i++;
	}
	ft_print_me(p);
}
