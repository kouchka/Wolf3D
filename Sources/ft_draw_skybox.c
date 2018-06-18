/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_skybox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:27:46 by allallem          #+#    #+#             */
/*   Updated: 2018/06/18 11:02:48 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_draw_skybox(t_thread *p, int start)
{
	int				i;
	float			teta;
	float			percent;
	unsigned char	*c;

	i = 0;
	teta = acos(p->p->plane.x / FOV);
	if (p->p->plane.y < 0)
		percent = teta / (2 * M_PI);
	else
		percent = -teta / (2 * M_PI);
	if (percent < 0)
		percent = 1 + percent;
	while (percent > 1)
		percent -= 1;
	while (i < start)
	{
		c = &p->p->tex_i[SKY].data[(int)((i % (p->p->tex_i[SKY].hei - 1))
		* p->p->tex_i[SKY].size_line) + ((int)(percent * p->p->tex_i[SKY].wid
		+ p->x) % (p->p->tex_i[SKY].wid - 1)) * 4];
		ft_put_pixel_thread(p, (i * p->p->image.size_line) + (p->x * 4),
		((c[2] << 16) | (c[1] << 8) | c[0]));
		i++;
	}
}
