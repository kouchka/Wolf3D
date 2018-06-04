/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_in_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:38:36 by allallem          #+#    #+#             */
/*   Updated: 2018/05/26 16:44:08 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_rotate(t_wolf3d *p)
{
	double oldDirx;
	double oldPlanex;

	oldDirx = p->v1.x;
	oldPlanex = p->plane.x;
	if (p->event.y == 2)
  {
		p->v1.x = p->v1.x * cos(-TETA) - p->v1.y * sin(-TETA);
		p->v1.y = oldDirx * sin(-TETA) + p->v1.y * cos(-TETA);
		p->plane.x = p->plane.x * cos(-TETA) - p->plane.y * sin(-TETA);
		p->plane.y = oldPlanex * sin(-TETA) + p->plane.y * cos(-TETA);
	}
	if (p->event.y == -2)
	{
		p->v1.x = p->v1.x * cos(TETA) - p->v1.y * sin(TETA);
	  p->v1.y = oldDirx * sin(TETA) + p->v1.y * cos(TETA);
		p->plane.x = p->plane.x * cos(TETA) - p->plane.y * sin(TETA);
		p->plane.y = oldPlanex * sin(TETA) + p->plane.y * cos(TETA);
	}
}
