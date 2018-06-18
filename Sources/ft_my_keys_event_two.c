/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_keys_event_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:27:20 by allallem          #+#    #+#             */
/*   Updated: 2018/06/18 10:28:46 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_free_music(t_wolf3d *p)
{
	int i;

	i = 0;
	while (i < SOUND)
	{
		Mix_FreeChunk(p->event.sound[i]);
		i++;
	}
	Mix_FreeMusic(p->event.music);
	Mix_CloseAudio();
}

void		ft_minimap(int key, t_wolf3d *p)
{
	if (key == KEY_8_NUM && p->mini.marge_y - 10 > 0)
		p->mini.marge_y -= 10;
	if (key == KEY_PLUS_NUM && p->mini.size_x < MINIMAPX * 6)
	{
		p->mini.size_x += MINIMAPX;
		p->mini.size_y += MINIMAPY;
		p->mini.marge_x -= MARGE_LEFT / 10;
		p->mini.marge_y -= MARGE_TOP / 10;
	}
	if (key == KEY_MINUS_NUM && (p->mini.size_x - MINIMAPX) > 0)
	{
		p->mini.size_x -= MINIMAPX;
		p->mini.size_y -= MINIMAPY;
		p->mini.marge_x += MARGE_LEFT / 10;
		p->mini.marge_y += MARGE_TOP / 10;
	}
	(key == KEY_N) ? p->event.transp += 0.05 : 0;
	if (key == KEY_B)
		p->event.transp -= 0.05;
	if (key == KEY_V && p->event.wow == 0)
		p->event.wow = 1;
	else if (key == KEY_V && p->event.wow == 1)
		p->event.wow = 0;
	if (key == KEY_C)
		p->event.transp = TRANSP;
}

void		ft_my_keys_event_three(int key, t_wolf3d *p)
{
	if (key == KEY_RIGHT)
		p->event.y = 2;
	if (key == KEY_LEFT)
		p->event.y = -2;
	if (key == KEY_R && p->event.bullet < 6 && p->event.bullet_bag > 0
		&& p->event.shot == 0 && p->event.pause == 0)
	{
		Mix_PlayChannel(0, p->event.sound[2], 0);
		p->event.bullet_bag -= 1;
		p->event.bullet += 1;
	}
	(key == KEY_D) ? p->event.y = 1 : 0;
	(key == KEY_L) ? p->event.lol += 1 : 0;
	if (key == KEY_P && p->event.pause == 0)
		p->event.pause = 1;
	else if (key == KEY_P && p->event.pause == 1)
		p->event.pause = 0;
}

void		ft_my_keys_event_two(int key, t_wolf3d *p)
{
	ft_minimap(key, p);
	if (key == KEY_2_NUM && p->mini.marge_y + 10 < WIN_Y)
		p->mini.marge_y += 10;
	if (key == KEY_6_NUM)
		p->mini.marge_x += 10;
	if (key == KEY_4_NUM && p->mini.marge_x - 10 > 0)
		p->mini.marge_x -= 10;
	if (key == KEY_A)
		p->event.y = -1;
	if (key == KEY_SHIFT_LEFT)
	{
		p->event.walk += p->event.walk;
		p->event.straf += p->event.straf;
	}
	if (key == KEY_W || key == KEY_UP)
		p->event.x = 1;
	if (key == KEY_S || key == KEY_DOWN)
		p->event.x = -1;
	if (key == ECHAP)
	{
		ft_free_music(p);
		exit(0);
	}
	ft_my_keys_event_three(key, p);
}
