/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_longlongint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:51:31 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:44:17 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi_longlongint(char const *str)
{
	int			i;
	int			signe;
	intmax_t	nb;

	nb = 0;
	signe = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == ' ' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (signe == -1)
		nb = nb * (-1);
	return (nb);
}
