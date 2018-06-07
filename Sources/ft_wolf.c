/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:15:27 by allallem          #+#    #+#             */
/*   Updated: 2018/06/06 17:45:27 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				ft_reset_img(t_wolf3d *p)
{
	mlx_destroy_image(p->mlx, p->image.img);
	p->image.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->image.data = (unsigned char *)mlx_get_data_addr(p->image.img,
	&p->image.bpp, &p->image.size_line, &p->image.endian);
}

void				ft_init(t_wolf3d *p)
{
	p->mlx = mlx_init();
	p->image.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->image.data = (unsigned char *)mlx_get_data_addr(p->image.img,
	&p->image.bpp, &p->image.size_line, &p->image.endian);
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, "Wolf_3D");
}

void				ft_get_color(t_wolf3d *p)
{
	if (!(p->color.tab = malloc(sizeof(int) * MAX_MAP)))
		ft_error(F_MAL);
	p->color.tab[0] = W1;
	p->color.tab[1] = W2;
	p->color.tab[2] = W3;
	p->color.tab[3] = W4;
	p->color.tab[4] = W5;
	p->color.tab[5] = W6;
	p->color.tab[6] = W7;
	p->color.tab[7] = W8;
	p->color.tab[8] = W9;
}

void				ft_wolf(t_wolf3d *p)
{
	ft_init(p);
	p->v1.x = -1;
	p->v1.y = 0;
	p->plane.x = 0;
	p->plane.y = FOV;
	p->mini.marge_x = MARGE_LEFT;
	p->mini.marge_y = MARGE_TOP;
	p->mini.size_x = MINIMAPX;
	p->mini.size_y = MINIMAPY;
	p->event.move = 1;
	p->event.walk = WALK;
	p->cam_move.x = 0;
	p->event.straf = STRAF;
	p->event.lol = 1;
	p->map.minimapx = MINIMAPX;
	p->map.minimapy = MINIMAPY;
	ft_get_color(p);
	ft_get_texture(p);
	mlx_hook(p->win, 17, 0L, my_button_events, NULL);
	mlx_hook(p->win, 6, (1L << 6), my_mouse_events, p);
	mlx_hook(p->win, 3, (1L << 1), my_keys_event_walk, p);
	mlx_hook(p->win, 2, (1L << 14), ft_my_keys_event, p);
	mlx_loop_hook(p->mlx, ft_game, p);
	mlx_loop(p->mlx);
}
