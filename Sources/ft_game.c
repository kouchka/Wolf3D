/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:54:50 by allallem          #+#    #+#             */
/*   Updated: 2018/06/02 11:53:11 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_put_pixel(t_thread *p, int x, int color)
{
	if (x < 0 || x > (WIN_X * WIN_Y) * 4)
		return ;
	p->p->image.data[x] = color & 0xFF;
	p->p->image.data[x + 1] = color >> 8 & 0xFF;
	p->p->image.data[x + 2] = color >> 16 & 0xFF;
}

void		ft_draw_wall(int start, int end, t_thread *p)
{
	int			texture;
	double	wallX;
	double	texX;
	int			texY;
	int color;
	int d;
	double	xew;
	unsigned char *c;

	texture = p->p->map.map[p->mapX][p->mapY] - 1;
	if (p->side == 0)
		wallX = p->p->cam.x + p->perpWallDist * p->raydir_Y;
	else
		wallX = p->p->cam.y + p->perpWallDist * p->raydir_X;
	wallX -= floor((wallX));
	texX = wallX * p->p->tex_i[texture].wid;
  if ((p->side == 0 && p->raydir_X > 0) || (p->side == 1 && p->raydir_Y < 0))
		texX = p->p->tex_i[texture].wid - texX;
	if (texture < 0)
		return;
	xew = p->p->tex_i[texture].wid - (int)texX -1;

	while (start < end)
	{
		d = start * 256 - WIN_Y * 128 + p->h * 128;
		texY = ((d * p->p->tex_i[texture].hei) / p->h) / 256;
		c = &p->p->tex_i[texture].data[((p->p->tex_i[texture].hei * texY) + (int)xew) * 4];
		color = c[2] & 0xFF;
		color = color << 8;
		color += c[1] & 0xFF;
		color = color << 8;
		color += c[0] & 0xFF;
		ft_put_pixel(p, (start * p->p->image.size_line) + (p->x * 4), color);
		start++;
	}
	color = 0x9E9E9E;
	while (start < WIN_Y)
	{
		ft_put_pixel(p, (start * p->p->image.size_line) + (p->x * 4), color);
		start++;
	}
}

void		*ft_play(void *value)
{
	t_thread *p;
	int lineHeight;
	int	drawStart;
	int drawend;

	p = (t_thread*)value;
	while (p->x < p->x_max)
	{
		p->camera_X = 2.0 * p->x / WIN_X - 1.0;
		p->raydir_X = p->p->v1.y + p->p->plane.y * p->camera_X;
		p->raydir_Y = p->p->v1.x + p->p->plane.x * p->camera_X;
		p->deltaDistX = fabs(1 / p->raydir_X);
		p->deltaDistY = fabs(1 / p->raydir_Y);
		p->mapX = (int)p->p->cam.y;
		p->mapY = (int)p->p->cam.x;
		p->hit = 0;
		p->side = 0;
		if (p->raydir_X < 0)
      {
        p->stepX = -1;
        p->sideDistX = (p->p->cam.y - p->mapX) * p->deltaDistX;
      }
      else
      {
        p->stepX = 1;
        p->sideDistX = (p->mapX + 1.0 - p->p->cam.y) * p->deltaDistX;
      }
      if (p->raydir_Y < 0)
      {
        p->stepY = -1;
        p->sideDistY = (p->p->cam.x - p->mapY) * p->deltaDistY;
      }
      else
      {
        p->stepY = 1;
        p->sideDistY = (p->mapY + 1.0 - p->p->cam.x) * p->deltaDistY;
      }
			while (p->mapX < p->p->map.y - 1 && p->mapY < p->p->map.x - 1  && p->hit == 0)
		 {
			 if (p->sideDistX < p->sideDistY)
			 {
				 p->sideDistX += p->deltaDistX;
				 p->mapX += p->stepX;
				 p->side = 0;
			 }
			 else
			 {
				 p->sideDistY += p->deltaDistY;
				 p->mapY += p->stepY;
				 p->side = 1;
			 }
			 if (p->p->map.map[p->mapX][p->mapY] > 0)
			 	p->hit = 1;
		 }
		if (p->side == 0)
			p->perpWallDist = (p->mapX - p->p->cam.y + (1.0 - p->stepX) / 2.0) / p->raydir_X;
		else
			p->perpWallDist = (p->mapY - p->p->cam.x + (1.0 - p->stepY) / 2.0) / p->raydir_Y;
		lineHeight = (int)(WIN_Y / p->perpWallDist);
		drawStart = -lineHeight / 2 + WIN_Y / 2;
    drawend = lineHeight / 2 + WIN_Y / 2;
		p->h = drawend - drawStart;
		if(drawStart < 0)
			drawStart = 0;
    if(drawend >= WIN_Y)
			drawend = WIN_Y - 1;
		if (p->hit == 1)
			ft_draw_wall(drawStart, drawend, p);
		p->x++;
	}
	pthread_exit(NULL);
}

void		ft_play_thread(t_wolf3d *p)
{
	int i;
	pthread_t tab[NB_THREAD];

	i = 0;
	while (i < NB_THREAD)
	{
		p->thread[i].x = i * AREA;
		p->thread[i].x_max = (i + 1) * AREA;
		p->thread[i].p = p;
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

void		ft_recalc(t_wolf3d *p)
{
	if ((p->cam.x - (int)p->cam.x) < CAP && p->map.map[(int)p->cam.y][(int)p->cam.x - 1])
		p->cam.x += CAP;
	if ((p->cam.y - (int)p->cam.y) < CAP && p->map.map[(int)p->cam.y - 1][(int)p->cam.x])
		p->cam.y += CAP;
	if (((int)(p->cam.x + CAP) > (int)p->cam.x) && p->map.map[(int)p->cam.y][(int)p->cam.x + 1])
		p->cam.x -= CAP;
	if (((int)(p->cam.y + CAP) > (int)p->cam.y) && p->map.map[(int)p->cam.y + 1][(int)p->cam.x])
		p->cam.y -= CAP;
}

void		ft_calc(t_wolf3d *p)
{
	if (p->event.x == 1 && !p->map.map[(int)p->cam.y][(int)(p->cam.x + p->v1.x * p->event.walk)])
		p->cam.x += p->v1.x * p->event.walk;
	if (p->event.x == 1 && !p->map.map[(int)(p->cam.y + p->v1.y * p->event.walk)][(int)p->cam.x])
		p->cam.y += p->v1.y * p->event.walk;
	if (p->event.x == -1 && !p->map.map[(int)p->cam.y][(int)(p->cam.x - p->v1.x * p->event.walk)])
		p->cam.x -= p->v1.x * p->event.walk;
	if (p->event.x == -1 && !p->map.map[(int)(p->cam.y - p->v1.y * p->event.walk)][(int)p->cam.x])
		p->cam.y -= p->v1.y * p->event.walk;
	if (p->event.y == 1 && !p->map.map[(int)p->cam.y][(int)(p->cam.x + p->plane.x * p->event.walk)])
		p->cam.x += p->plane.x * p->event.walk;
	if (p->event.y == 1 && !p->map.map[(int)(p->cam.y + p->plane.y * p->event.walk)][(int)p->cam.x])
		p->cam.y += p->plane.y * p->event.walk;
	if (p->event.y == -1 && !p->map.map[(int)(p->cam.y - p->plane.y * p->event.walk)][(int)p->cam.x])
		p->cam.y -= p->plane.y * p->event.walk;
	if (p->event.y == -1 && !p->map.map[(int)p->cam.y][(int)(p->cam.x - p->plane.x * p->event.walk)])
		p->cam.x -= p->plane.x * p->event.walk;
	ft_recalc(p);
	if (p->event.y == 2 || p->event.y == -2)
		ft_rotate(p);
}

void		ft_put_pause_menu(t_wolf3d * p)
{
	mlx_string_put(p->mlx, p->win, WIN_X / 2, 0, 0xFFFFFF, "PAUSED");
}

void		ft_swap_texture(t_wolf3d *p)
{
	int i;
	int j;

	i = 0;
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

	if (p->event.pause == 0)
	{
		ft_calc(p);
		ft_reset_img(p);
		ft_play_thread(p);
		mlx_put_image_to_window (p->mlx, p->win, p->image.img, 0, 0);

	}
	else if (p->event.pause == 1)
		ft_put_pause_menu(p);
	swap ++;
	if (swap == SWAP)
	{
		swap = 0;
		ft_swap_texture(p);
	}
	return (1);
}
