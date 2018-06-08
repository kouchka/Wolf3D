/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:19:59 by allallem          #+#    #+#             */
/*   Updated: 2018/06/08 18:12:36 by allallem         ###   ########.fr       */
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
	int			color;

	color = c[2] & 0xFF;
	color = color << 8;
	color += c[1] & 0xFF;
	color = color << 8;
	color += c[0] & 0xFF;
	return (color);
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

int		ft_interpolate(int color, unsigned char *c, float tp)
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


void		ft_print_ground(t_wolf3d *p, int i, int j)
{
	int ix;
	int igrec;
	int check;

	igrec = 0;
	while (igrec < p->mini.ymap)
	{
		ix = 0;
		while (ix < p->mini.xmap)
		{
			if ((check = (((i * p->mini.ymap) + igrec + p->mini.marge_y) *
p->image.size_line) + ((j * p->mini.xmap) + p->mini.marge_x + ix) * 4) /
p->image.size_line == (((i * p->mini.ymap) + igrec + p->mini.marge_y)))
				ft_put_pixel(p, check, ft_interpolate(GROUND, &p->image.data[check], p->event.transp));
			ix++;
		}
		igrec++;
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
