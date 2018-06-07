/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:24:56 by allallem          #+#    #+#             */
/*   Updated: 2018/06/06 17:30:40 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			my_button_events(int key)
{
	if (key == 0)
		exit(EXIT_SUCCESS);
	return (1);
}

int			my_mouse_events(int x, int y, t_wolf3d *p)
{
	double olddirx;
	double oldplanex;
	double teta;

	if (p->event.pause == 0)
	{
		teta = ((p->cam_move.x - x) / WIN_X) * ROTSPEED;
		y = 0;
		p->cam_move.x = x;
		p->cam_move.y = y;
		olddirx = p->v1.x;
		oldplanex = p->plane.x;
		p->v1.x = p->v1.x * cos(teta) - p->v1.y * sin(teta);
		p->v1.y = olddirx * sin(teta) + p->v1.y * cos(teta);
		p->plane.x = p->plane.x * cos(teta) - p->plane.y * sin(teta);
		p->plane.y = oldplanex * sin(teta) + p->plane.y * cos(teta);
	}
	return (1);
}

int			my_keys_event_walk(int key, t_wolf3d *p)
{
	if (key == KEY_SHIFT_LEFT)
	{
		p->event.walk = WALK;
		p->event.straf = STRAF;
	}
	if (key == KEY_A || key == KEY_D || key == KEY_RIGHT || key == KEY_LEFT)
		p->event.y = 0;
	if (key == KEY_SHIFT_LEFT)
		p->event.speed += p->event.speed;
	if (key == KEY_W || key == KEY_S || key == KEY_UP || key == KEY_DOWN)
		p->event.x = 0;
	return (1);
}

int			ft_my_keys_event(int key, t_wolf3d *p)
{
	if (key == KEY_M && p->event.map == 0)
		p->event.map = 1;
	else if (key == KEY_M && p->event.map == 1)
		p->event.map = 0;
	if (key == KEY_P && p->event.pause == 0)
		p->event.pause = 1;
	else if (key == KEY_P && p->event.pause == 1)
		p->event.pause = 0;
	if (key == KEY_D)
		p->event.y = 1;
	if (key == KEY_L)
		p->event.lol += 1;
	ft_my_keys_event_two(key, p);
	return (1);
}
