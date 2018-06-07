/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:08:28 by allallem          #+#    #+#             */
/*   Updated: 2018/01/12 17:07:38 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putoctal(unsigned int nbr)
{
	int		j;
	char	*str;
	char	*toprint;
	char	*result;

	if (nbr == 0)
		ft_putnbr(0);
	str = "01234567";
	j = ft_strlen(result);
	toprint = malloc(sizeof(char) * j);
	toprint[j] = '\0';
	while (nbr > 0)
	{
		j--;
		toprint[j] = str[nbr % 8];
		nbr /= 8;
	}
	ft_putstr(toprint + j);
	free(toprint);
	return (j);
}
