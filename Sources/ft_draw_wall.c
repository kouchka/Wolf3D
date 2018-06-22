/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 03:33:41 by allallem          #+#    #+#             */
/*   Updated: 2018/06/22 13:16:18 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_initialisation(t_thread *p)
{
	p->texture = p->p->map.map[p->mapx][p->mapy] - 1;
	if ((int)p->p->cam.x <= p->mapy && p->texture == 3 && p->side == 1)
		p->texture += 1;
	else if ((int)p->p->cam.x > p->mapy && p->texture == 3 && p->side == 1)
		p->texture += 2;
	else if (p->p->cam.y < p->mapx && p->texture == 3 && p->side == 0)
		p->texture += 3;
	if (p->side == 0)
		p->wallx = p->p->cam.x + p->perpwalldist * p->raydir_y;
	else
		p->wallx = p->p->cam.y + p->perpwalldist * p->raydir_x;
	p->wallx -= floor((p->wallx));
	p->texx = p->wallx * p->p->tex_i[p->texture].wid;
	if ((p->side == 0 && p->raydir_x > 0) || (p->side == 1 && p->raydir_y < 0))
		p->texx = p->p->tex_i[p->texture].wid - p->texx;
	p->xew = p->p->tex_i[p->texture].wid - (int)p->texx - 1;
	if (p->x == WIN_X / 2 && p->p->ennemi == 0)
	{
		p->p->x = p->mapx;
		p->p->y = p->mapy;
	}
}

void		ft_draw_wall(int start, int end, t_thread *p)
{
	int				i;
	int				d;
	unsigned char	*c;

	i = 0;
	ft_initialisation(p);
	if (p->texture < 0)
		return ;
	ft_draw_skybox(p, start);
	while (start < end)
	{
		d = (start - p->p->event.z) * 256 - WIN_Y * 128 + p->h * 128;
		p->texy = ((d * p->p->tex_i[p->texture].hei) / p->h) / 256;
		c = &p->p->tex_i[p->texture].data[((int)(p->p->tex_i[p->texture].hei
		* p->texy) + (int)p->xew) * 4];
		ft_put_pixel_thread(p, (start * p->p->image.size_line) + (p->x * 4),
		((c[2] << 16) | (c[1] << 8) | c[0]));
		start++;
	}
	while (start < WIN_Y)
	{
		ft_put_pixel_thread(p, (start * p->p->image.size_line)
		+ (p->x * 4), GROUND);
		start++;
	}
}
