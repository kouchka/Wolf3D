/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 03:24:39 by allallem          #+#    #+#             */
/*   Updated: 2018/06/22 13:18:53 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_get_ennemie(t_thread *p)
{
	int i;

	i = 0;
	while (i < p->sprite->nbr)
	{
		if ((int)p->sprite->pos[i].x == (int)p->mapy && (int)p->sprite->pos[i].y == (int)p->mapx && p->sprite->pos[i].hp != 0)
		{
			p->p->ennemi = 1;
			p->p->x = i;
			return ;
		}
		i++;
	}
}

void		ft_swap_sprites(t_wolf3d *p)
{
	if (p->sprite.way == 0 && p->sprite.anim < SPRITE_ALIVE)
		p->sprite.anim++;
	else if (p->sprite.way == -1 && p->sprite.anim > 0)
		p->sprite.anim--;
	if (p->sprite.anim == SPRITE_ALIVE)
	{
		p->sprite.way = -1;
		p->sprite.anim--;
	}
	else if (p->sprite.anim == 0)
		p->sprite.way = 0;
}

void		ft_put_pixel(t_wolf3d *p, int x, int color)
{
	if (x < 0 || x > (WIN_X * WIN_Y) * 4)
		return ;
	if (x % 4 != 0)
		x -= x % 4;
	p->image.data[x] = color & 0xFF;
	p->image.data[x + 1] = color >> 8 & 0xFF;
	p->image.data[x + 2] = color >> 16 & 0xFF;
	p->image.data[x + 3] = color >> 24 & 0xFF;
}

int			ft_interpolate(int color, unsigned char *c, float tp)
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
