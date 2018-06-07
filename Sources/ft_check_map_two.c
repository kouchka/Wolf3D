/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:20:16 by allallem          #+#    #+#             */
/*   Updated: 2018/06/06 18:39:00 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_get_value(char **map, int i, int *j, int *k)
{
	while (ft_isdigit(map[i][*k]))
		*k = *k + 1;
	*j = *j + 1;
}

void			ft_assign_tab_value(t_wolf3d *p, char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < p->map.y)
	{
		j = 0;
		k = 0;
		while (j < p->map.x)
		{
			while (map[i][k] && map[i][k] == ' ')
				k++;
			if (map[i][k] && ft_isdigit(map[i][k]))
			{
				p->map.map[i][j] = ft_atoi(map[i] + k);
				ft_get_value(map, i, &j, &k);
			}
			else
				j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}

static void		ft_check_digit(char **map, int *j, int *count, int i)
{
	while (map[i][*j])
	{
		if (ft_isdigit(map[i][*j]))
		{
			while (ft_isdigit(map[i][*j]))
				*j = *j + 1;
			*count = *count + 1;
		}
		if (map[i][*j])
			*j = *j + 1;
	}
}

int				ft_size_x(char **map, t_wolf3d *p)
{
	int	i;
	int	j;
	int	count;
	int	value;

	value = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		count = 0;
		ft_check_digit(map, &j, &count, i);
		if (count > value)
			value = count;
		i++;
	}
	p->map.y = i;
	p->map.x = value;
	return (value);
}
