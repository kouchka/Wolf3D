/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:19:59 by allallem          #+#    #+#             */
/*   Updated: 2018/06/19 06:50:54 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_print_me(t_wolf3d *p)
{
	int			i;
	int			j;
	float		y;
	int			check;

	i = -p->mini.xmap / 8;
	while (i < (int)p->mini.xmap / 8)
	{
		j = -p->mini.xmap / 8;
		while (j < p->mini.xmap / 8)
		{
			y = p->image.size_line * ((p->cam.y *
			p->mini.ymap + p->mini.marge_y + i));
			if (fmod(y, p->image.size_line) != 0)
				y -= fmod(y, p->image.size_line);
			if ((check = y + (((p->cam.x * p->mini.xmap)
			+ p->mini.marge_x + j) * 4))
			/ p->image.size_line == (y / p->image.size_line))
				ft_put_pixel(p, check, 0xFF0000);
			j++;
		}
		i++;
	}
	ft_trace_fov(p);
}

int			ft_calculate_color(unsigned char *c)
{
	return (((c[2] << 16) | (c[1] << 8) | c[0]));
}

void		ft_calculate_map(t_wolf3d *p, int i, int j, unsigned char *c)
{
	int				loly;
	int				lolx;
	int				check;
	int				diffx;
	int				diffy;

	diffy = p->tex_i[p->map.map[i][j] - 1].hei / p->mini.ymap;
	diffx = p->tex_i[p->map.map[i][j] - 1].wid / p->mini.xmap;
	loly = -1;
	while (++loly < p->mini.ymap)
	{
		lolx = -1;
		while (++lolx < p->mini.xmap)
		{
			if ((check = (((i * p->mini.ymap) + loly + p->mini.marge_y) *
p->image.size_line) + ((j * p->mini.xmap) + p->mini.marge_x + lolx) * 4) /
p->image.size_line == (((i * p->mini.ymap) + loly + p->mini.marge_y)))
			{
				c = &p->tex_i[p->map.map[i][j] - 1].data[(int)((p->tex_i[
		p->map.map[i][j] - 1].size_line *
		(loly * diffy)) + ((lolx * diffx)) * 4)];
				ft_put_pixel(p, check, ft_calculate_color(c));
			}
		}
	}
}

void		ft_print_ground(t_wolf3d *p, int i, int j)
{
	int x;
	int y;
	int check;

	y = 0;
	while (y < p->mini.ymap)
	{
		x = 0;
		while (x < p->mini.xmap)
		{
			if ((check = (((i * p->mini.ymap) + y + p->mini.marge_y) *
p->image.size_line) + ((j * p->mini.xmap) + p->mini.marge_x + x) * 4) /
p->image.size_line == (((i * p->mini.ymap) + y + p->mini.marge_y)) &&
	check < (WIN_X * WIN_Y) * 4)
				ft_put_pixel(p, check, ft_interpolate(GROUND,
					&p->image.data[check], p->event.transp));
			x++;
		}
		y++;
	}
}

void		ft_print_map(t_wolf3d *p)
{
	int				i;
	int				j;
	unsigned char	*c;

	c = NULL;
	i = 0;
	p->mini.xmap = p->mini.size_x / p->map.x - 1;
	p->mini.ymap = p->mini.size_y / p->map.y;
	while (i < p->map.y)
	{
		j = 0;
		while (j < p->map.x)
		{
			if (p->map.map[i][j])
				ft_calculate_map(p, i, j, c);
			else
				ft_print_ground(p, i, j);
			j++;
		}
		i++;
	}
	ft_print_me(p);
}
