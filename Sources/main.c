/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:05:24 by allallem          #+#    #+#             */
/*   Updated: 2018/06/06 17:25:24 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_error(char *str)
{
	if (ft_strequ(str, W_VALUE))
		ft_printf("%s[%i-%i]\n", str, MIN_MAP, MAX_MAP);
	else
		ft_printf("%s", str);
	exit(EXIT_SUCCESS);
}

void	ft_get_pos(t_wolf3d *p)
{
	int i;
	int j;

	i = 1;
	while (i < p->map.y - 1 && p->cam.y == 0)
	{
		j = 0;
		while (j < p->map.x && p->cam.x == 0)
		{
			if (p->map.map[i][j] == 0)
			{
				p->cam.x = j;
				p->cam.y = i;
			}
			j++;
		}
		i++;
	}
	if (p->cam.y == 0)
		ft_error(W_MAP);
}

void	ft_recheck_map(t_wolf3d *p)
{
	int i;

	i = 0;
	while (i < p->map.x)
	{
		if (!p->map.map[0][i])
			p->map.map[0][i] = WALL_ERR;
		if (!p->map.map[p->map.y - 1][i])
			p->map.map[p->map.y - 1][i] = WALL_ERR;
		i++;
	}
	i = 0;
	while (i < p->map.y)
	{
		if (!p->map.map[i][0])
			p->map.map[i][0] = WALL_ERR;
		if (!p->map.map[i][p->map.x - 1])
			p->map.map[i][p->map.x - 1] = WALL_ERR;
		i++;
	}
	ft_get_pos(p);
}

int		main(int argc, char **argv)
{
	t_wolf3d p;

	ft_bzero(&p, sizeof(t_wolf3d));
	if (argc > 1 && ft_check_map(argv[1], &p))
	{
		ft_recheck_map(&p);
		ft_wolf(&p);
	}
	else
		ft_printf(USAGE);
	return (1);
}
