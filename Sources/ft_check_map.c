/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:42:25 by allallem          #+#    #+#             */
/*   Updated: 2018/06/06 18:28:17 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		ft_get_it(char **map, t_wolf3d *p)
{
	int	i;
	int	j;

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
	int		i;
	int		j;
	char	**tab;

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
	int	i;

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

void			ft_work_on_temp(char **map, char **tmp, char *str)
{
	if (*map == NULL)
		*map = ft_strdup(str);
	else
	{
		*tmp = *map;
		*map = ft_strjoin(*map, str);
		free(*tmp);
	}
}

int				ft_check_map(char *fd, t_wolf3d *p)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*map;

	if ((i = open(fd, O_RDONLY)) < 0)
		return (ft_error(W_FILE));
	map = NULL;
	str = NULL;
	while (get_next_line(i, &str) > 0)
	{
		if (!ft_check_numbers(str))
			return (0);
		tmp = str;
		str = ft_strjoin(str, "\n");
		free(tmp);
		ft_work_on_temp(&map, &tmp, str);
		free(str);
	}
	return (ft_treat_map(p, map));
}
