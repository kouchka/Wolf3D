/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_skybox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:27:46 by allallem          #+#    #+#             */
/*   Updated: 2018/06/08 14:41:38 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_draw_skybox(t_thread *p, int start)
{
		int i;
		float percent;
		unsigned char *c;
		int		color;

		i = 0;
		if (p->p->plane.y < 0)
			percent = (FOV - p->p->plane.x) / (FOV * 2);
		else
			percent = (FOV + p->p->plane.x) / (FOV * 2);
		while (i < start)
		{
			c = &p->p->tex_i[SKY].data[(int)(i * p->p->tex_i[SKY].size_line) + (int)(percent * p->p->tex_i[SKY].wid + p->x) * 4];
			color = c[2] & 0xFF;
			color = color << 8;
			color += c[1] & 0xFF;
			color = color << 8;
			color += c[0] & 0xFF;
			ft_put_pixel_thread(p, (i * p->p->image.size_line) + (p->x * 4), color);
			i++;
		}
}
