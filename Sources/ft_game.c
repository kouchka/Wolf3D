/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:54:50 by allallem          #+#    #+#             */
/*   Updated: 2018/06/22 13:38:13 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_put_pixel_thread(t_thread *p, int x, int color)
{
	if (x < 0 || x >= (WIN_X * WIN_Y) * 4 || p->p->image.data[x])
		return ;
	p->p->image.data[x] = color & 0xFF;
	p->p->image.data[x + 1] = color >> 8 & 0xFF;
	p->p->image.data[x + 2] = color >> 16 & 0xFF;
}

void		ft_play_thread(t_wolf3d *p)
{
	int				i;
	pthread_t		tab[NB_THREAD];

	i = 0;
	while (i < NB_THREAD)
	{
		p->thread[i].x = i * (WIN_X / NB_THREAD);
		p->thread[i].x_max = (i + 1) * (WIN_X / NB_THREAD);
		p->thread[i].p = p;
		p->thread[i].nbr = i;
		p->thread[i].sprite = &p->sprite;
		if (pthread_create(&tab[i], NULL, ft_play, &p->thread[i]))
			ft_error(ERROR_CT);
		i++;
	}
	i = 0;
	while (i < NB_THREAD)
	{
		if (pthread_join(tab[i], NULL))
			ft_error(ERROR_T);
		i++;
	}
}

void		ft_put_pause_menu(t_wolf3d *p)
{
	mlx_string_put(p->mlx, p->win, WIN_X / 2, 0, 0xFFFFFF, "PAUSED");
}

void		ft_swap_texture(t_wolf3d *p, int *swap)
{
	int i;
	int j;

	i = 0;
	*swap = 0;
	while (i < p->map.y)
	{
		j = 0;
		while (j < p->map.x)
		{
			if (p->map.map[i][j] == ANIME_FIRST)
				p->map.map[i][j] = ANIME_SECOND;
			else if (p->map.map[i][j] == ANIME_SECOND)
				p->map.map[i][j] = ANIME_FIRST;
			j++;
		}
		i++;
	}
}

int			ft_game(t_wolf3d *p)
{
	static int swap;

	p->ennemi = 0;
	if (p->event.pause == 0)
	{
		ft_calc(p);
		ft_reset_img(p);
		if (p->event.intro == 0)
			ft_intro(p);
		else
		{
			ft_play_thread(p);
			(p->event.map == 1) ? ft_print_map(p) : 0;
			ft_shot(p);
		}
		mlx_put_image_to_window(p->mlx, p->win, p->image.img, 0, 0);
		(p->event.intro) ? ft_print_bullet(p) : 0;
	}
	else if (p->event.pause == 1)
		ft_put_pause_menu(p);
	if (swap++ == SWAP)
		ft_swap_texture(p, &swap);
	else if (!(swap % 9))
		ft_swap_sprites(p);
	p->sprite.move++;
	return (1);
}
