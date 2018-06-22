/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 03:46:58 by allallem          #+#    #+#             */
/*   Updated: 2018/06/22 14:35:28 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_step_one(t_thread *p)
{
	p->camera_x = 2.0 * p->x / WIN_X - 1.0;
	p->raydir_x = p->p->v1.y + p->p->plane.y * p->camera_x;
	p->raydir_y = p->p->v1.x + p->p->plane.x * p->camera_x;
	p->deltadistx = fabs(1 / p->raydir_x);
	p->deltadisty = fabs(1 / p->raydir_y);
	p->mapx = (int)p->p->cam.y;
	p->mapy = (int)p->p->cam.x;
	p->hit = 0;
	p->side = 0;
}

void		ft_step_two(t_thread *p)
{
	if (p->raydir_x < 0)
	{
		p->stepx = -1;
		p->sidedistx = (p->p->cam.y - p->mapx) * p->deltadistx;
	}
	else
	{
		p->stepx = 1;
		p->sidedistx = (p->mapx + 1.0 - p->p->cam.y) * p->deltadistx;
	}
	if (p->raydir_y < 0)
	{
		p->stepy = -1;
		p->sidedisty = (p->p->cam.x - p->mapy) * p->deltadisty;
	}
	else
	{
		p->stepy = 1;
		p->sidedisty = (p->mapy + 1.0 - p->p->cam.x) * p->deltadisty;
	}
}

void		ft_step_three(t_thread *p)
{
	while (p->mapx < p->p->map.y - 1 && p->mapy < p->p->map.x
	- 1 && p->hit == 0)
	{
		if (p->sidedistx < p->sidedisty)
		{
			p->sidedistx += p->deltadistx;
			p->mapx += p->stepx;
			p->side = 0;
		}
		else
		{
			p->sidedisty += p->deltadisty;
			p->mapy += p->stepy;
			p->side = 1;
		}
		if (p->p->map.map[p->mapx][p->mapy] > 0)
			p->hit = 1;
		if (p->x == WIN_X / 2 && p->p->ennemi == 0)
			ft_get_ennemie(p);
	}
	if (p->side == 0)
		p->perpwalldist = (p->mapx - p->p->cam.y + (1.0 - p->stepx)
		/ 2.0) / p->raydir_x;
	else
		p->perpwalldist = (p->mapy - p->p->cam.x + (1.0 - p->stepy)
		/ 2.0) / p->raydir_y;
	p->sprite->sp[p->x] = p->perpwalldist;
}

void		*ft_play(void *value)
{
	t_thread	*p;
	int			lineheight;
	int			drawstart;
	int			drawend;

	p = (t_thread*)value;
	while (p->x < p->x_max)
	{
		ft_step_one(p);
		ft_step_two(p);
		ft_step_three(p);
		lineheight = (int)(WIN_Y / p->perpwalldist);
		drawstart = (-lineheight / 2 + WIN_Y / 2) + p->p->event.z;
		drawend = (lineheight / 2 + WIN_Y / 2) + p->p->event.z;
		p->h = drawend - drawstart;
		if (drawstart < 0)
			drawstart = 0;
		if (drawend >= WIN_Y)
			drawend = WIN_Y - 1;
		if (p->hit == 1)
			ft_draw_wall(drawstart, drawend, p);
		p->x++;
	}
	ft_calc_trace_sprites(p);
	pthread_exit(NULL);
}
