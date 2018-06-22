/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 10:58:30 by allallem          #+#    #+#             */
/*   Updated: 2018/06/22 13:37:10 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_put_pixel_sprite(t_thread *p, int x, int color)
{
	if (x < 0 || x >= (WIN_X * WIN_Y) * 4)
		return ;
	p->p->image.data[x] = (color & 0xFF) | 0x01;
	p->p->image.data[x + 1] = color >> 8 & 0xFF;
	p->p->image.data[x + 2] = color >> 16 & 0xFF;
}

void			ft_trace_sprites(t_thread *p, int size, int start)
{
	int					i;
	int					j;
	int					y;
	int					d;
	int					spriteorder[size];
	int					stripe;
	int					frame;
	float				spritedistance[size];
	unsigned char		*c;

	i = 0;
	j = start;
	while (i < size)
	{
		spriteorder[i] = j;
		spritedistance[i] = ((p->p->cam.x - p->sprite->pos[j].x) * (p->p->cam.x
		- p->sprite->pos[j].x) + (p->p->cam.y - p->sprite->pos[j].y) *
		(p->p->cam.y - p->sprite->pos[j].y));
		i++;
		j++;
	}
	/*combSort(spriteorder, spritedistance, size);*/
	i = 0;
	while (i < size)
	{
		if (p->sprite->pos[spriteorder[i]].dead == 0)
		{
			frame = p->sprite->anim;
			if (p->sprite->pos[spriteorder[i]].hp == 0)
				frame += SPRITE_ALIVE;
			if (frame == SPRITE - 1)
				p->sprite->pos[spriteorder[i]].dead = 1;
		}
		else
			frame = SPRITE - 1;
		p->spritex = p->sprite->pos[spriteorder[i]].x - p->p->cam.x;
		p->spritey = p->sprite->pos[spriteorder[i]].y - p->p->cam.y;
		p->invdet = 1.0 / (p->p->plane.x * p->p->v1.y - p->p->v1.x *
			p->p->plane.y);
		p->transformx = p->invdet * (p->p->v1.y * p->spritex - p->p->v1.x
			* p->spritey);
		p->transformy = p->invdet * (-p->p->plane.y * p->spritex +
		p->p->plane.x * p->spritey);
		p->spritescreenx = (int)((WIN_X / 2) * (1 + p->transformx
			/ p->transformy));
		p->spriteheight = abs((int)(WIN_Y / (p->transformy)));
		p->drawstarty = -p->spriteheight / 2 + WIN_Y / 2;
		if (p->drawstarty < 0)
			p->drawstarty = 0;
		p->drawendy = p->spriteheight / 2 + WIN_Y / 2;
		if (p->drawendy >= WIN_Y)
			p->drawendy = WIN_Y - 1;
		p->spritewidth = abs((int)(WIN_Y / (p->transformy)));
		p->drawstartx = -p->spritewidth / 2 + p->spritescreenx;
		if (p->drawstartx < 0)
			p->drawstartx = 0;
		p->drawendx = p->spritewidth / 2 + p->spritescreenx;
		if (p->drawendx >= WIN_X)
			p->drawendx = WIN_X - 1;
		stripe = p->drawstartx;
		while (stripe < p->drawendx)
		{
			p->texx_s = (int)(256 * (stripe - (-p->spritewidth / 2 +
	p->spritescreenx)) * p->sprite->image[frame].wid /
	p->spritewidth) / 256;
			y = p->drawstarty + p->p->event.z;
			if (p->transformy > 0 && stripe > 0 && stripe < WIN_X &&
				p->transformy < p->sprite->sp[stripe])
			{
				while (y < p->drawendy + p->p->event.z)
				{
					d = (y - p->p->event.z) * 256 - WIN_Y * 128 +
					p->spriteheight * 128;
					p->texy_s = (int)((d *
					p->sprite->image[frame].hei)
					/ p->spriteheight) / 256;
					if (p->sprite->pos[spriteorder[i]].xmove == -1)
						c = &p->sprite->image[frame].data[(int)(
p->sprite->image[frame].size_line * p->texy_s)
	+ (p->texx_s) * 4];
					else
						c = &p->sprite->image[frame].data[(int)(
p->sprite->image[frame].size_line * p->texy_s)
	+ (p->sprite->image[frame].wid - 1 - p->texx_s) * 4];
					if (!(c[3] == 0xFF))
						ft_put_pixel_sprite(p, (y * p->p->image.size_line)
						+ (stripe * 4),
					((c[2] << 16) | (c[1] << 8) | c[0]));
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}

void			ft_calc_trace_sprites(t_thread *p)
{
	int i;
	int j;

	i = p->sprite->nbr / NB_THREAD; // a calculer plus tot pour éviter de calculer trop de fois
	j = p->sprite->nbr % NB_THREAD; // idem ici
	// à vérifier plus tard
	if (j == 0)
		ft_trace_sprites(p, i, i * p->nbr);
	else
	{
		if (j > p->nbr)
			ft_trace_sprites(p, i + 1, i * p->nbr + p->nbr);
		else
			ft_trace_sprites(p, i, i * p->nbr + j);
	}
}
