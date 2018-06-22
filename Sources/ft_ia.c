/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:58:47 by allallem          #+#    #+#             */
/*   Updated: 2018/06/22 13:10:17 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				ft_move(t_thread *ia)
{
	ia->x = 0;
	if (ia->sprite->move >= MOVE_SPRITE)
	{
		while (ia->x < ia->sprite->nbr)
		{
			if (ia->sprite->pos[ia->x].hp != 0)
			{
				if (ia->sprite->pos[ia->x].xmove == 0)
				{
					if (ia->sprite->pos[ia->x].x + 1 < ia->p->map.x - 1)
						ia->sprite->pos[ia->x].x += 0.2;
					else
						ia->sprite->pos[ia->x].xmove = -1;
				}
				else if (ia->sprite->pos[ia->x].xmove == -1)
				{
					if (ia->sprite->pos[ia->x].x - 1 > 0.5)
					ia->sprite->pos[ia->x].x -= 0.2;
					else
					ia->sprite->pos[ia->x].xmove = 0;
				}
			}
			ia->x++;
		}
		ia->sprite->move = 0;
	}
}

void				*ft_ia(void *value)
{
	t_thread *ia;

	ia = (t_thread*)value;
	while (ia->p->event.exit == 0)
		ft_move(ia);
	pthread_exit(NULL);
}
