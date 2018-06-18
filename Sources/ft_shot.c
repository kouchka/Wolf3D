/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:05:09 by allallem          #+#    #+#             */
/*   Updated: 2018/06/18 11:24:53 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_print_weapon(t_wolf3d *p)
{
	int				i;
	int				j;
	unsigned char	*c;

	i = 0;
	while (i < p->shot[0].hei - 1)
	{
		j = 0;
		while (j < p->shot[0].wid - 1)
		{
			c = &p->shot[0].data[((i * p->shot[0].size_line) + (j * 4))];
			if (!(c[3] == 0xFF))
				ft_put_pixel(p, ((WIN_Y - p->shot[0].hei + i) *
	p->image.size_line) + ((WIN_X / 2 + p->shot[0].wid + j) * 4), ((c[2] << 16)
	| (c[1] << 8) | c[0]));
			j++;
		}
		i++;
	}
}

static void		ft_print_animation(t_wolf3d *p, int img)
{
	int				i;
	int				j;
	unsigned char	*c;

	i = 0;
	while (i < p->shot[img].hei)
	{
		j = 0;
		while (j < p->shot[img].wid)
		{
			c = &p->shot[img].data[(int)((i * p->shot[img].size_line)
			+ (j * 4))];
			if (!(c[3] == 0xFF))
				ft_put_pixel(p, ((WIN_Y - p->shot[img].hei + i) *
	p->image.size_line) + ((WIN_X / 2 + p->shot[img].wid + j) * 4),
	((c[2] << 16) + (c[1] << 8) + c[0]));
			j++;
		}
		i++;
	}
}

void			ft_shot(t_wolf3d *p)
{
	static int i;
	static int j;

	if (p->event.shot == 0)
		ft_print_weapon(p);
	else
	{
		ft_print_animation(p, j);
		if ((i % SHOT_T) == 0 && p->event.order == 1)
			j++;
		else if ((i % SHOT_T) == 0 && p->event.order == -1)
			j--;
		if ((i % SHOT_T) == 0 && j >= SHOT)
		{
			p->event.order = -1;
			j--;
		}
		if (j == 0 && p->event.order == -1)
		{
			i = 0;
			p->event.shot = 0;
			return ;
		}
		i++;
	}
}

void			ft_print_bullet(t_wolf3d *p)
{
	char *str;

	str = NULL;
	if (p->event.bullet != 0)
	{
		str = ft_itoa(p->event.bullet);
		mlx_string_put(p->mlx, p->win, WIN_X * 0.95, WIN_Y *
		0.90, 0xFFFFFF, str);
		free(str);
	}
	else
		mlx_string_put(p->mlx, p->win, WIN_X * 0.95, WIN_Y *
		0.90, 0xFFFFFF, "0");
	str = ft_itoa(p->event.bullet_bag);
	mlx_string_put(p->mlx, p->win, WIN_X * 0.95, WIN_Y * 0.95, 0xFFFFFF, str);
	free(str);
}
