/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 03:48:16 by allallem          #+#    #+#             */
/*   Updated: 2018/06/14 03:51:32 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_recalc(t_wolf3d *p)
{
	if (p->event.y == -1 && !p->map.map[(int)p->cam.y]
	[(int)(p->cam.x - p->plane.x * p->event.walk)])
		p->cam.x -= p->plane.x * p->event.walk;
	if ((p->cam.x - (int)p->cam.x) < CAP && p->map.map[(int)p->cam.y]
	[(int)p->cam.x - 1])
		p->cam.x += CAP;
	if ((p->cam.y - (int)p->cam.y) < CAP && p->map.map[(int)p->cam.y - 1]
	[(int)p->cam.x])
		p->cam.y += CAP;
	if (((int)(p->cam.x + CAP) > (int)p->cam.x) && p->map.map[(int)p->cam.y]
	[(int)p->cam.x + 1])
		p->cam.x -= CAP;
	if (((int)(p->cam.y + CAP) > (int)p->cam.y) &&
	p->map.map[(int)p->cam.y + 1][(int)p->cam.x])
		p->cam.y -= CAP;
}

void		ft_calc(t_wolf3d *p)
{
	if (p->event.x == 1 && !p->map.map[(int)p->cam.y]
	[(int)(p->cam.x + p->v1.x * p->event.walk)])
		p->cam.x += p->v1.x * p->event.walk;
	if (p->event.x == 1 && !p->map.map[(int)
	(p->cam.y + p->v1.y * p->event.walk)][(int)p->cam.x])
		p->cam.y += p->v1.y * p->event.walk;
	if (p->event.x == -1 && !p->map.map[(int)p->cam.y]
	[(int)(p->cam.x - p->v1.x * p->event.walk)])
		p->cam.x -= p->v1.x * p->event.walk;
	if (p->event.x == -1 && !p->map.map[(int)
	(p->cam.y - p->v1.y * p->event.walk)][(int)p->cam.x])
		p->cam.y -= p->v1.y * p->event.walk;
	if (p->event.y == 1 && !p->map.map[(int)p->cam.y]
	[(int)(p->cam.x + p->plane.x * p->event.walk)])
		p->cam.x += p->plane.x * p->event.walk;
	if (p->event.y == 1 && !p->map.map[(int)
	(p->cam.y + p->plane.y * p->event.walk)][(int)p->cam.x])
		p->cam.y += p->plane.y * p->event.walk;
	if (p->event.y == -1 && !p->map.map[(int)
	(p->cam.y - p->plane.y * p->event.walk)][(int)p->cam.x])
		p->cam.y -= p->plane.y * p->event.walk;
	ft_recalc(p);
	if (p->event.y == 2 || p->event.y == -2)
		ft_rotate(p);
}
