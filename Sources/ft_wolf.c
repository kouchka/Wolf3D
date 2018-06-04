/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:15:27 by allallem          #+#    #+#             */
/*   Updated: 2018/06/04 13:52:10 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_reset_img(t_wolf3d *p)
{
	mlx_destroy_image(p->mlx, p->image.img);
	p->image.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->image.data = (unsigned char *)mlx_get_data_addr(p->image.img, &p->image.bpp
		, &p->image.size_line, &p->image.endian);
}

void		ft_init(t_wolf3d *p)
{
	p->mlx = mlx_init();
	p->image.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->image.data = (unsigned char *)mlx_get_data_addr(p->image.img, &p->image.bpp
		, &p->image.size_line, &p->image.endian);
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

void				ft_get_texture(t_wolf3d *p)
{
	p->tex_i[0].add = mlx_xpm_file_to_image(p->mlx, W1_T, &p->tex_i[0].wid, &p->tex_i[0].hei);
	p->tex_i[0].data = (unsigned char *)mlx_get_data_addr(p->tex_i[0].add, &p->tex_i[0].bpp, &p->tex_i[0].size_line, &p->tex_i[0].endian);
	p->tex_i[1].add = mlx_xpm_file_to_image(p->mlx, W2_T, &p->tex_i[1].wid, &p->tex_i[1].hei);
	p->tex_i[1].data = (unsigned char *)mlx_get_data_addr(p->tex_i[1].add, &p->tex_i[1].bpp, &p->tex_i[1].size_line, &p->tex_i[1].endian);
	p->tex_i[2].add = mlx_xpm_file_to_image(p->mlx, W3_T, &p->tex_i[2].wid, &p->tex_i[2].hei);
	p->tex_i[2].data = (unsigned char *)mlx_get_data_addr(p->tex_i[2].add, &p->tex_i[2].bpp, &p->tex_i[2].size_line, &p->tex_i[2].endian);
	p->tex_i[3].add = mlx_xpm_file_to_image(p->mlx, W4_T, &p->tex_i[3].wid, &p->tex_i[3].hei);
	p->tex_i[3].data = (unsigned char *)mlx_get_data_addr(p->tex_i[3].add, &p->tex_i[3].bpp, &p->tex_i[3].size_line, &p->tex_i[3].endian);
	p->tex_i[4].add = mlx_xpm_file_to_image(p->mlx, W5_T, &p->tex_i[4].wid, &p->tex_i[4].hei);
	p->tex_i[4].data = (unsigned char *)mlx_get_data_addr(p->tex_i[4].add, &p->tex_i[4].bpp, &p->tex_i[4].size_line, &p->tex_i[4].endian);
	p->tex_i[5].add = mlx_xpm_file_to_image(p->mlx, W6_T, &p->tex_i[5].wid, &p->tex_i[5].hei);
	p->tex_i[5].data = (unsigned char *)mlx_get_data_addr(p->tex_i[5].add, &p->tex_i[5].bpp, &p->tex_i[5].size_line, &p->tex_i[5].endian);
	p->tex_i[6].add = mlx_xpm_file_to_image(p->mlx, W7_T, &p->tex_i[6].wid, &p->tex_i[6].hei);
	p->tex_i[6].data = (unsigned char *)mlx_get_data_addr(p->tex_i[6].add, &p->tex_i[6].bpp, &p->tex_i[6].size_line, &p->tex_i[6].endian);
	p->tex_i[7].add = mlx_xpm_file_to_image(p->mlx, W8_T, &p->tex_i[7].wid, &p->tex_i[7].hei);
	p->tex_i[7].data = (unsigned char *)mlx_get_data_addr(p->tex_i[7].add, &p->tex_i[7].bpp, &p->tex_i[7].size_line, &p->tex_i[7].endian);
	p->tex_i[8].add = mlx_xpm_file_to_image(p->mlx, W9_T, &p->tex_i[8].wid, &p->tex_i[8].hei);
	p->tex_i[8].data = (unsigned char *)mlx_get_data_addr(p->tex_i[8].add, &p->tex_i[8].bpp, &p->tex_i[8].size_line, &p->tex_i[8].endian);
	p->tex_i[9].add = mlx_xpm_file_to_image(p->mlx, SKYBOX, &p->tex_i[9].wid, &p->tex_i[9].hei);
	p->tex_i[9].data = (unsigned char *)mlx_get_data_addr(p->tex_i[9].add, &p->tex_i[9].bpp, &p->tex_i[9].size_line, &p->tex_i[9].endian);
	p->tex_i[10].add = NULL;
}

void	 			ft_wolf(t_wolf3d *p)
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
	mlx_hook(p->win, 2, (1L << 14), my_keys_event, p);
	mlx_loop_hook(p->mlx, ft_game, p);
	mlx_loop(p->mlx);
}
