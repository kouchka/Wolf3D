/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:59:50 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:44:43 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_init_pfspe(t_pfspe *point)
{
	point->h = 0;
	point->l = 0;
	point->j = 0;
	point->z = 0;
	point->diese = 0;
	point->zero = 0;
	point->minus = 0;
	point->plus = 0;
	point->space = 0;
	point->point = 0;
	point->result = 0;
	point->field = 0;
	point->precision = 0;
	point->cursor = 0;
	point->size_content = 0;
}

static int		ft_check_error(char const *str, t_pfspe *point)
{
	int i;

	i = 0;
	while (ft_strstr_int("0 +-#", str[i]) && str[i])
		i++;
	point->field = ft_atoi_longlongint(str + i);
	while (ft_strstr_int("0123456789", str[i]) && str[i])
		i++;
	if (ft_strstr_int(".", str[i]) && str[i])
		i++;
	point->precision = ft_atoi_longlongint(str + i);
	while ((ft_strstr_int("0123456789", str[i])) && str[i])
		i++;
	if (!(i = i + ft_verification_last(str + i)))
		return (0);
	if (!(ft_strstr_int("sSpdDioOuUxXcC", str[i])) || str[i] == '\0')
		return (0);
	return (i);
}

static int		ft_check_param(char c, t_pfspe *point, void *content)
{
	if (c == 'd' || c == 'i' || c == 'D')
		ft_printfdi(c, point, (long long int)content);
	else if (c == 's')
		ft_printfs(point, (char *)content);
	else if (c == 'p')
		ft_putaddress_printf(content, c, point, 16);
	else if (c == 'x')
		ft_putaddress_printf(content, c, point, 16);
	else if (c == 'X')
		ft_putaddress_printf(content, c, point, 16);
	else if (c == 'o' || c == 'O')
		ft_putaddress_printf(content, c, point, 8);
	else
		return (0);
	return (1);
}

int				ft_flags(char const *str, void *content, t_pfspe *point)
{
	int i;

	ft_init_pfspe(point);
	i = 0;
	if (!(point->result = ft_check_error(str, point)))
		return (0);
	i = ft_fillstruct_printf(point, str);
	ft_check_param(str[i], point, content);
	return (point->result);
}
