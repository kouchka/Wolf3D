/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:42:25 by allallem          #+#    #+#             */
/*   Updated: 2018/06/01 12:34:03 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void 	ft_assign_tab_value(t_wolf3d *p, char **map)
{
	int i;
	int j;
	int k;

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
				while (ft_isdigit(map[i][k]))
					k++;
				j++;
			}
			else
				j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}

static int		ft_size_x(char **map, t_wolf3d *p)
{
	int i;
	int j;
	int count;
	int value;

	value = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		count = 0;
		while (map[i][j])
		{
			if (ft_isdigit(map[i][j]))
			{
				while (ft_isdigit(map[i][j]))
					j++;
				count++;
			}
			if (map[i][j])
				j++;
		}
		if (count > value)
			value = count;
		i++;
	}
	p->map.y = i;
	p->map.x = value;
	return (value);
}

static int		ft_get_it(char **map, t_wolf3d *p)
{
	int i;
	int j;

	j = 0;
	i = ft_tablen(map);
	if (!(p->map.map = malloc(sizeof(int *) * i)))
		return (ft_error(F_MAL));
	i = 0;
	j = ft_size_x(map, p);
	while (i < p->map.y)
	{
		if (!(p->map.map[i] = ft_memalloc(sizeof(int) * j)))
			return (ft_error(F_MAL));
		i++;
	}
	ft_assign_tab_value(p, map);
	return (1);
}

static int		ft_treat_map(t_wolf3d *p, char *map)
{
	int i;
	int j;
	char **tab;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i])
	{
		while (map[i] == ' ')
			i++;
		if (map[i] != '\n' && ((j = ft_atoi(map + i)) > MAX_MAP || j < MIN_MAP))
			return (ft_error(W_VALUE));
		i++;
	}

	tab = ft_strsplit(map, '\n');
	free(map);
	return (ft_get_it(tab, p));
}

static int		ft_check_numbers(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\0' && str[i] != '\n')
			return (ft_error(W_MAP));
		if (str[i] != '\0')
			i++;
	}
	return (1);
}

int						ft_check_map(char *fd, t_wolf3d *p)
{
	int i;
	char *str;
	char *tmp;
	char *map;

	if ((i = open(fd, O_RDONLY)) < 0)
		return (ft_error(W_FILE));
	map = NULL;
	tmp = NULL;
	str = NULL;
	while (get_next_line(i, &str) > 0)
	{
		if (!ft_check_numbers(str))
			return (0);
		tmp = str;
		str = ft_strjoin(str, "\n");
		free(tmp);
		if (map == NULL)
			map = ft_strdup(str);
		else
		{
			tmp = map;
			map = ft_strjoin(map, str);
			free(tmp);
		}
		free(str);
	}
	return (ft_treat_map(p, map));
}
