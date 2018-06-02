/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:24:56 by allallem          #+#    #+#             */
/*   Updated: 2018/06/01 16:39:31 by allallem         ###   ########.fr       */
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
	if (p->event.pause == 0)
	{
		double oldDirx;
		double oldPlanex;
		double teta;

		teta = ((p->cam_move.x - x) / WIN_X) * ROTSPEED;
		y = 0;
		p->cam_move.x = x;
		p->cam_move.y = y;
		oldDirx = p->v1.x;
		oldPlanex = p->plane.x;
		p->v1.x = p->v1.x * cos(teta) - p->v1.y * sin(teta);
  	p->v1.y = oldDirx * sin(teta) + p->v1.y * cos(teta);
		p->plane.x = p->plane.x * cos(teta) - p->plane.y * sin(teta);
		p->plane.y = oldPlanex * sin(teta) + p->plane.y * cos(teta);
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
	if (key == KEY_W || key == KEY_S || key == KEY_UP ||  key == KEY_DOWN)
		p->event.x = 0;
	return (1);
}

int			my_keys_event(int key, t_wolf3d *p)
{
	if (key == KEY_P && p->event.pause == 0)
		p->event.pause = 1;
	else if (key == KEY_P && p->event.pause == 1)
		p->event.pause = 0;
	if (key == KEY_D)
		p->event.y = 1;
	if (key == KEY_L)
		p->event.lol += 1;
	if (key == KEY_A)
		p->event.y = -1;
	if (key == KEY_SHIFT_LEFT)
	{
		p->event.walk += p->event.walk;
		p->event.straf += p->event.straf;
	}
	if (key == KEY_W || key == KEY_UP)
		p->event.x = 1;
	if (key == KEY_S || key == KEY_DOWN)
		p->event.x = -1;
	if (key == ECHAP)
		exit(0);
	if (key == KEY_RIGHT)
  	p->event.y = 2;
	if (key == KEY_LEFT)
		p->event.y = -2;
	return (1);
}
