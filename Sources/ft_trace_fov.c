/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_fov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:58:28 by allallem          #+#    #+#             */
/*   Updated: 2018/06/08 17:38:59 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_init_seg(t_wolf3d *p, float *yjump)
{
	p->fov.xdiff = ft_abs(p->fov.xdiff);
	p->fov.ydiff = ft_abs(p->fov.ydiff);
	(p->fov.xdiff >= p->fov.ydiff) ? *yjump = p->fov.ydiff / p->fov.xdiff : 0;
	(p->fov.ydiff >= p->fov.xdiff) ? *yjump = p->fov.xdiff / p->fov.ydiff : 0;
	p->fov.temp = *yjump;
}

void		ft_redirect(t_wolf3d *p)
{
	if (p->fov.xdiff > 0 && p->fov.ydiff >= 0 && p->fov.xdiff >= p->fov.ydiff)
		ft_trace_up_left_right(p, 1);
	else if (p->fov.xdiff > 0 && p->fov.ydiff < 0 && p->fov.xdiff >= ft_abs(p->fov.ydiff))
		ft_trace_bottom_right_left(p, 1);
	else if (p->fov.xdiff < 0 && p->fov.ydiff >= 0 && ft_abs(p->fov.xdiff) >= p->fov.ydiff)
		ft_trace_up_left_right(p, 0);
	else if (p->fov.xdiff < 0 && p->fov.ydiff < 0
		&& ft_abs(p->fov.xdiff) >= ft_abs(p->fov.ydiff))
		ft_trace_bottom_right_left(p, 0);
	else if (p->fov.xdiff < 0 && p->fov.ydiff < 0
		&& ft_abs(p->fov.xdiff) <= ft_abs(p->fov.ydiff))
		ft_trace_bottom_left_right(p, 0);
	else if (p->fov.xdiff > 0 && p->fov.ydiff < 0 && p->fov.xdiff <= ft_abs(p->fov.ydiff))
		ft_trace_bottom_left_right(p, 1);
	else if (p->fov.xdiff < 0 && p->fov.ydiff > 0 && ft_abs(p->fov.xdiff) <= p->fov.ydiff)
		ft_trace_up_right_left(p, 0);
	else if (p->fov.xdiff >= 0 && p->fov.ydiff > 0 && p->fov.xdiff <= p->fov.ydiff)
		ft_trace_up_right_left(p, 1);
	else if (p->fov.xdiff == 0 && (p->fov.ydiff < 0 || p->fov.ydiff > 0))
		ft_trace_baton(p);
}

void		ft_trace_fov(t_wolf3d *p)
{
	p->fov.x1 = p->cam.x * p->mini.xmap + p->mini.marge_x;
	p->fov.y1 = p->cam.y * p->mini.ymap + p->mini.marge_y;
	p->fov.x2 = p->fov.x1 + (p->v1.x * p->mini.xmap);
	p->fov.y2 = p->fov.y1 + (p->v1.y * p->mini.xmap);
	p->fov.xdiff = p->fov.x2 - p->fov.x1;
	p->fov.ydiff = p->fov.y1 - p->fov.y2;
	ft_redirect(p);
}
