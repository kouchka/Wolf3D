/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:04:27 by allallem          #+#    #+#             */
/*   Updated: 2018/06/22 13:34:29 by allallem         ###   ########.fr       */
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
# include <SDL_mixer.h>
# define W_MAP "Map is Wrong\n"
# define W_FILE "File doesn't exist\n"
# define F_MAL "malloc failed\n"
# define USAGE "usage: ./wolf3d [maps/Mapfile]\n"
# define W_VALUE "Wrong value on map "
# define W_SPRITE "Wrong value on sprite "
# define ERROR_T "Error on Thead join"
# define ERROR_CT "Thread creation failed"
# define WIN_X 1920
# define SOUND 3
# define WIN_Y 1080
# define MIN_MAP 0
# define MAX_MAP 9
# define MAX_SPR 1
# define MIN_SPR 0
# define SKY 9
# define SHOT 4
# define WAIT 0
# define SHOT_T 4
# define INTRO_T 10
# define TEXTURE 12
# define SPRITE 6
# define SPRITE_ALIVE 3
# define MOVE_SPRITE 10
# define GROUND 0x9E9E9E
# define NB_THREAD 7
# define WALL_ERR 9
# define TRANSP 0.25
# define SWAP 60
# define FOV 0.77
# define ANIME_FIRST 9
# define ANIME_SECOND 8
# define AREA WIN_X / NB_THREAD
# define MINIMAPX WIN_Y / 10
# define MINIMAPY WIN_Y / 10
# define MARGE_TOP WIN_Y / 4
# define MARGE_LEFT WIN_X / 4
# define SPEED 0.10
# define WALK 0.05
# define STRAF 0.02
# define ROTSPEED 5
# define TETA 0.05
# define CAP 0.055

typedef struct s_wolf3d		t_wolf3d;

typedef struct					s_fov
{
	float			xdiff;
	float			ydiff;
	float			temp;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}								t_fov;

typedef struct					s_vector
{
	double						x;
	double						y;
}								t_vector;

typedef struct					s_event
{
	Mix_Music					*music;
	Mix_Chunk					*sound[SOUND];
	int							bullet;
	int							bullet_bag;
	int							map;
	int							x;
	int							y;
	int							z;
	int							pause;
	int							exit;
	int							move;
	int							lol;
	int							order;
	int							shot;
	int							hit;
	int							intro;
	float						transp;
	double						walk;
	double						speed;
	double						straf;
}								t_event;

typedef struct					s_map
{
	int							**map;
	int							x;
	int							y;
	int							minimapy;
	int							minimapx;
}								t_map;

typedef struct					s_image
{
	void						*img;
	unsigned char				*data;
	int							bpp;
	int							endian;
	int							size_line;
}								t_image;

typedef struct					s_texture
{
	void						*add;
	int							wid;
	int							hei;
	unsigned char				*data;
	int							bpp;
	int							endian;
	int							size_line;
}								t_texture;

typedef struct					s_type
{
	float	x;
	float	y;
	int		dead;
	int		hp;
	int		type;
	int		xmove;
	int		ymove;
}								t_type;

typedef struct					s_sprite
{
	t_texture			image[SPRITE];
	int					anim;
	int					nbr;
	int					way;
	int					move;
	t_type				*pos;
	double				sp[WIN_X];
}								t_sprite;

typedef struct					s_thread
{
	int							h;
	int							nbr;
	int							x;
	int							x_max;
	int							hit;
	int							side;
	int							stepx;
	int							texx_s;
	int							texy_s;
	int							stepy;
	int							mapx;
	int							mapy;
	int							spritescreenx;
	int							spriteheight;
	int							drawstarty;
	int							drawendy;
	int							spritewidth;
	int							drawstartx;
	int							drawendx;
	int							texture;
	double						xew;
	double						texy;
	double						texx;
	double						wallx;
	double						camera_x;
	double						raydir_x;
	double						raydir_y;
	double						spritex;
	double						spritey;
	double						invdet;
	double						transformx;
	double						transformy;
	double						sidedistx;
	double						sidedisty;
	double						deltadistx;
	double						deltadisty;
	double						perpwalldist;
	int							*spriteorder;
	float						*spritedistance;
	t_sprite					*sprite;
	t_wolf3d					*p;
}								t_thread;

typedef struct					s_minimap
{
	int							size_x;
	int							size_y;
	int							marge_x;
	int							marge_y;
	float						xmap;
	float						ymap;
}								t_minimap;

struct							s_wolf3d
{
	void						*mlx;
	void						*win;
	int							x;
	int							y;
	int							ennemi;
	t_vector					cam_move;
	t_image						image;
	t_map						map;
	t_texture					tex_i[TEXTURE];
	t_sprite					sprite;
	t_vector					cam;
	t_vector					v1;
	t_vector					plane;
	t_event						event;
	t_thread					thread[NB_THREAD];
	t_minimap					mini;
	t_fov						fov;
	t_texture					shot[SHOT];
};

int								ft_check_map(char *str, t_wolf3d *p);
int								ft_error(char *str);
void							ft_wolf(t_wolf3d *p);
int								ft_my_keys_event(int key, t_wolf3d *p);
void							ft_minimap(int key, t_wolf3d *p);
void							ft_my_keys_event_two(int key, t_wolf3d *p);
int								ft_game(t_wolf3d *p);
void							ft_reset_img(t_wolf3d *p);
int								my_keys_event_walk(int key, t_wolf3d *p);
int								my_mouse_events(int x, int y, t_wolf3d *p);
int								my_button_events(int key, t_wolf3d *p);
void							ft_rotate(t_wolf3d *p);
void							ft_print_map(t_wolf3d *p);
void							ft_trace_bottom_right_left(t_wolf3d *p, int i);
void							ft_trace_up_left_right(t_wolf3d *p, int i);
void							ft_trace_bottom_left_right(t_wolf3d *p, int i);
void							ft_trace_up_right_left(t_wolf3d *p, int i);
void							ft_trace_baton(t_wolf3d *p);
void							ft_put_pixel(t_wolf3d *p, int x, int color);
void							ft_get_texture(t_wolf3d *p);
void							ft_assign_tab_value(t_wolf3d *p, char **map);
int								ft_size_x(char **map, t_wolf3d *p);
void							ft_draw_skybox(t_thread *p, int start);
void							ft_put_pixel_thread(t_thread *p, int x,
									int color);
void							ft_init_minimap(int *diffy, int *diffx,
									int *loly);
void							ft_trace_fov(t_wolf3d *p);
void							ft_trace_baton(t_wolf3d *p);
void							ft_trace_up_left_right(t_wolf3d *p, int i);
void							ft_trace_up_right_left(t_wolf3d *p, int i);
void							ft_trace_bottom_left_right(t_wolf3d *p, int i);
void							ft_trace_bottom_right_left(t_wolf3d *p, int i);
void							ft_init_seg(t_wolf3d *p, float *yjump);
void							ft_intro(t_wolf3d *p);
int								ft_interpolate(int color, unsigned char *c,
									float tp);
void							ft_draw_wall(int start, int end, t_thread *p);
void							ft_calc(t_wolf3d *p);
void							*ft_play(void *value);
void							ft_shot(t_wolf3d *p);
void							ft_free_music(t_wolf3d *p);
void							ft_print_bullet(t_wolf3d *p);
void							ft_calc_trace_sprites(t_thread *p);
void							*ft_ia(void *value);
void							ft_swap_sprites(t_wolf3d *p);
void							ft_get_ennemie(t_thread *p);

#endif
