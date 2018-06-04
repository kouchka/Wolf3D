/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:51:08 by allallem          #+#    #+#             */
/*   Updated: 2018/03/08 16:55:20 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_number(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i])
		{
			while (str[i] != ' ' && str[i])
				i++;
			nbr++;
		}
		else
			i++;
	}
	return (nbr);
}
