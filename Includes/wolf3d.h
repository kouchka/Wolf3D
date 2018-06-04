/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:04:27 by allallem          #+#    #+#             */
/*   Updated: 2018/06/04 17:45:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <time.h>
# include "keys.h"
# include "color.h"
/*MAP*/
# define WIN_X 1920
# define WIN_Y 1080
# define MIN_MAP 0
# define MAX_MAP 9
/*MINIMAP*/
# define MINIMAPX WIN_X / 10
# define MINIMAPY WIN_Y / 10
# define MARGE_TOP WIN_Y / 4
# define MARGE_LEFT WIN_X / 4
# define SKY 10
# define NB_THREAD 8
# define WALL_ERR 9
# define SWAP 60
# define W_MAP "Map is Wrong\n"
# define W_FILE "File doesn't exist\n"
# define F_MAL "malloc failed\n"
# define USAGE "usage: ./wolf3d [maps/Mapfile]\n"
# define W_VALUE "Wrong value on map "
# define ERROR_T "Error on Thead join"
# define ERROR_CT "Thread creation failed"
# define BLOCK_S 64
# define MY_S BLOCK_S / 2
# define FOV 0.77
# define ANIME_FIRST 9
# define ANIME_SECOND 8
# define AREA WIN_X / NB_THREAD
# define SPEED 0.10
# define WALK 0.05
# define STRAF 0.02
# define ROTSPEED 5
# define TETA 0.05
# define CAP 0.055

typedef struct	s_wolf3d	t_wolf3d;

typedef struct s_color
{
	int	*tab;
}							t_color;

typedef struct	t_vector
{
	double 							x;
	double 							y;
}								t_vector;

typedef struct	s_first_vector
{
	double 							x;
	double 							y;
}								t_first_vector;

typedef struct	s_second_raycaster
{
	double							 x;
	double							 y;
}								t_second_raycaster;

typedef struct	s_cam_move
{
	double x;
	double y;
}								t_cam_move;

typedef struct	s_cam
{
	double							 x;
	double							 y;
}								t_cam;

typedef struct	s_event
{
	int									map;
	int									x;
	int									y;
	int									pause;
	int									move;
	int									lol;
	double							walk;
	double							speed;
	double							straf;
}								t_event;

typedef struct	s_map
{
	int									**map;
	int									x;
	int									y;
	int									minimapy;
	int									minimapx;
}							t_map;

typedef struct	s_image
{
	void								*img;
	unsigned char				*data;
	int									bpp;
	int									endian;
	int									size_line;
}							t_image;

typedef struct	s_texture
{
	void						*add;
	int							wid;
	int							hei;
	unsigned char 	*data;
	int							bpp;
	int							endian;
	int							size_line;
}								t_texture;

typedef struct	s_thread
{
	int									h;
	int									x;
	int									x_max;
	int									hit;
	int									side;
	int									stepX;
	int									stepY;
	int									mapX;
	int									mapY;
	double							camera_X;
	double							raydir_X;
	double							raydir_Y;
	double							sideDistX;
	double							sideDistY;
	double							deltaDistX;
	double							deltaDistY;
	double							perpWallDist;
	t_wolf3d 						*p;
}									t_thread;

typedef struct	s_minimap
{
	int		size_x;
	int		size_y;
	int		marge_x;
	int		marge_y;
	float xmap;
	float ymap;
}								t_minimap;

struct		s_wolf3d
{
	void								*mlx;
	void								*win;
	t_cam_move					cam_move;
	t_image							image;
	t_map								map;
	t_texture						tex_i[MAX_MAP + 2];
	t_cam								cam;
	t_first_vector			v1;
	t_second_raycaster	plane;
	t_event							event;
	t_thread						thread[NB_THREAD];
	t_color							color;
	t_minimap						mini;
};

int								ft_check_map(char *str, t_wolf3d *p);
int								ft_error(char *str);
void 							ft_wolf(t_wolf3d *p);
int								my_keys_event(int key, t_wolf3d *p);
int								ft_game(t_wolf3d *p);
void							ft_reset_img(t_wolf3d *p);
int								my_keys_event_walk(int key, t_wolf3d *p);
int								my_mouse_events(int x, int y, t_wolf3d *p);
int								my_button_events(int key);
void							ft_rotate(t_wolf3d *p);
void							ft_print_map(t_wolf3d *p);
void							ft_trace_bottom_right_left(t_wolf3d *p, int i);
void							ft_trace_up_left_right(t_wolf3d *p, int i);
void							ft_trace_bottom_left_right(t_wolf3d *p, int i);
void							ft_trace_up_right_left(t_wolf3d *p, int i);
void							ft_trace_baton(t_wolf3d *p);
void							ft_put_pixel(t_wolf3d *p, int x, int color);

#endif
