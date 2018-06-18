/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_seg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:17:13 by allallem          #+#    #+#             */
/*   Updated: 2018/06/14 03:45:17 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_trace_baton(t_wolf3d *p)
{
	int		j;

	j = 0;
	p->fov.ydiff = ft_abs(p->fov.ydiff);
	while (j < p->fov.ydiff)
	{
		ft_put_pixel(p, (p->fov.x1 * 4) + (p->image.size_line
			* p->fov.y1), 0x00FF00);
		p->fov.y1++;
		j++;
	}
}

void		ft_trace_up_left_right(t_wolf3d *p, int i)
{
	float	yjump;
	int		j;

	j = 0;
	ft_init_seg(p, &yjump);
	while (j < p->fov.xdiff)
	{
		if (yjump >= 1)
		{
			p->fov.y1--;
			yjump = yjump - 1;
		}
		if (i == 0)
			ft_put_pixel(p, ((p->fov.x1 - j) * 4) +
			(p->image.size_line * p->fov.y1), 0x00FF00);
		else if (i == 1)
			ft_put_pixel(p, ((p->fov.x1 + j) * 4) +
			(p->image.size_line * p->fov.y1), 0x00FF00);
		yjump += p->fov.temp;
		j++;
	}
}

void		ft_trace_up_right_left(t_wolf3d *p, int i)
{
	float	yjump;
	int		j;

	j = 0;
	ft_init_seg(p, &yjump);
	while (j < p->fov.xdiff || j < p->fov.ydiff)
	{
		if (yjump >= 1 && i == 0)
		{
			p->fov.x1--;
			yjump -= 1;
		}
		else if (yjump >= 1 && i == 1)
		{
			p->fov.x1++;
			yjump -= 1;
		}
		ft_put_pixel(p, (((p->fov.x1 * 4) +
		((p->image.size_line) * p->fov.y1))), 0x00FF00);
		j++;
		p->fov.y1--;
		yjump += p->fov.temp;
	}
}

void		ft_trace_bottom_left_right(t_wolf3d *p, int i)
{
	float	yjump;
	int		j;

	j = 0;
	ft_init_seg(p, &yjump);
	while (j < p->fov.xdiff || j < p->fov.ydiff)
	{
		if (yjump >= 1 && i == 0)
		{
			p->fov.x1--;
			yjump -= 1;
		}
		else if (yjump >= 1 && i == 1)
		{
			p->fov.x1++;
			yjump -= 1;
		}
		ft_put_pixel(p, (((p->fov.x1 * 4) +
		((p->image.size_line) * p->fov.y1))), 0x00FF00);
		j++;
		p->fov.y1++;
		yjump += p->fov.temp;
	}
}

void		ft_trace_bottom_right_left(t_wolf3d *p, int i)
{
	float	yjump;
	int		j;

	j = 0;
	ft_init_seg(p, &yjump);
	while (j < p->fov.xdiff)
	{
		if (yjump >= 1)
		{
			p->fov.y1++;
			yjump = yjump - 1;
		}
		if (i == 1)
			ft_put_pixel(p, ((p->fov.x1 + j) * 4) +
			(p->image.size_line * p->fov.y1), 0x00FF00);
		else if (i == 0)
			ft_put_pixel(p, ((p->fov.x1 - j) * 4) +
			(p->image.size_line * p->fov.y1), 0x00FF00);
		j++;
		yjump += p->fov.temp;
	}
}
