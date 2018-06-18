/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:40:00 by allallem          #+#    #+#             */
/*   Updated: 2018/06/18 02:23:04 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_get_shot(t_wolf3d *p)
{
	p->tex_i[10].data = (unsigned char *)mlx_get_data_addr(p->tex_i[10].add,
		&p->tex_i[10].bpp, &p->tex_i[10].size_line, &p->tex_i[10].endian);
	p->tex_i[11].add = NULL;
	p->shot[0].add = mlx_xpm_file_to_image(p->mlx, SHOT_ONE, &p->shot[0].wid,
		&p->shot[0].hei);
	p->shot[0].data = (unsigned char *)mlx_get_data_addr(p->shot[0].add,
		&p->shot[0].bpp, &p->shot[0].size_line, &p->shot[0].endian);
	p->shot[1].add = mlx_xpm_file_to_image(p->mlx, SHOT_TWO, &p->shot[1].wid,
		&p->shot[1].hei);
	p->shot[1].data = (unsigned char *)mlx_get_data_addr(p->shot[1].add,
		&p->shot[1].bpp, &p->shot[1].size_line, &p->shot[1].endian);
	p->shot[2].add = mlx_xpm_file_to_image(p->mlx, SHOT_THR, &p->shot[2].wid,
		&p->shot[2].hei);
	p->shot[2].data = (unsigned char *)mlx_get_data_addr(p->shot[2].add,
		&p->shot[2].bpp, &p->shot[2].size_line, &p->shot[2].endian);
	p->shot[3].add = mlx_xpm_file_to_image(p->mlx, SHOT_FOR, &p->shot[3].wid,
		&p->shot[3].hei);
	p->shot[3].data = (unsigned char *)mlx_get_data_addr(p->shot[3].add,
		&p->shot[3].bpp, &p->shot[3].size_line, &p->shot[3].endian);
}

static void	ft_get_texture_two(t_wolf3d *p)
{
	p->tex_i[5].add = mlx_xpm_file_to_image(p->mlx, W6_T, &p->tex_i[5].wid,
		&p->tex_i[5].hei);
	p->tex_i[5].data = (unsigned char *)mlx_get_data_addr(p->tex_i[5].add,
		&p->tex_i[5].bpp, &p->tex_i[5].size_line, &p->tex_i[5].endian);
	p->tex_i[6].add = mlx_xpm_file_to_image(p->mlx, W7_T, &p->tex_i[6].wid,
		&p->tex_i[6].hei);
	p->tex_i[6].data = (unsigned char *)mlx_get_data_addr(p->tex_i[6].add,
		&p->tex_i[6].bpp, &p->tex_i[6].size_line, &p->tex_i[6].endian);
	p->tex_i[7].add = mlx_xpm_file_to_image(p->mlx, W8_T, &p->tex_i[7].wid,
		&p->tex_i[7].hei);
	p->tex_i[7].data = (unsigned char *)mlx_get_data_addr(p->tex_i[7].add,
		&p->tex_i[7].bpp, &p->tex_i[7].size_line, &p->tex_i[7].endian);
	p->tex_i[8].add = mlx_xpm_file_to_image(p->mlx, W9_T, &p->tex_i[8].wid,
		&p->tex_i[8].hei);
	p->tex_i[8].data = (unsigned char *)mlx_get_data_addr(p->tex_i[8].add,
		&p->tex_i[8].bpp, &p->tex_i[8].size_line, &p->tex_i[8].endian);
	p->tex_i[9].add = mlx_xpm_file_to_image(p->mlx, SKYBOX, &p->tex_i[9].wid,
		&p->tex_i[9].hei);
	p->tex_i[9].data = (unsigned char *)mlx_get_data_addr(p->tex_i[9].add,
		&p->tex_i[9].bpp, &p->tex_i[9].size_line, &p->tex_i[9].endian);
	p->tex_i[10].add = mlx_xpm_file_to_image(p->mlx, INTRO, &p->tex_i[10].wid,
		&p->tex_i[10].hei);
	ft_get_shot(p);
}

void		ft_get_texture(t_wolf3d *p)
{
	p->tex_i[0].add = mlx_xpm_file_to_image(p->mlx, W1_T, &p->tex_i[0].wid,
		&p->tex_i[0].hei);
	p->tex_i[0].data = (unsigned char *)mlx_get_data_addr(p->tex_i[0].add,
		&p->tex_i[0].bpp, &p->tex_i[0].size_line, &p->tex_i[0].endian);
	p->tex_i[1].add = mlx_xpm_file_to_image(p->mlx, W2_T, &p->tex_i[1].wid,
		&p->tex_i[1].hei);
	p->tex_i[1].data = (unsigned char *)mlx_get_data_addr(p->tex_i[1].add,
				&p->tex_i[1].bpp, &p->tex_i[1].size_line, &p->tex_i[1].endian);
	p->tex_i[2].add = mlx_xpm_file_to_image(p->mlx, W3_T, &p->tex_i[2].wid,
		&p->tex_i[2].hei);
	p->tex_i[2].data = (unsigned char *)mlx_get_data_addr(p->tex_i[2].add,
		&p->tex_i[2].bpp, &p->tex_i[2].size_line, &p->tex_i[2].endian);
	p->tex_i[3].add = mlx_xpm_file_to_image(p->mlx, W4_T, &p->tex_i[3].wid,
		&p->tex_i[3].hei);
	p->tex_i[3].data = (unsigned char *)mlx_get_data_addr(p->tex_i[3].add,
		&p->tex_i[3].bpp, &p->tex_i[3].size_line, &p->tex_i[3].endian);
	p->tex_i[4].add = mlx_xpm_file_to_image(p->mlx, W5_T, &p->tex_i[4].wid,
		&p->tex_i[4].hei);
	p->tex_i[4].data = (unsigned char *)mlx_get_data_addr(p->tex_i[4].add,
		&p->tex_i[4].bpp, &p->tex_i[4].size_line, &p->tex_i[4].endian);
	ft_get_texture_two(p);
}
