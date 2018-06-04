/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:58:29 by allallem          #+#    #+#             */
/*   Updated: 2018/01/08 22:41:36 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(char *result, int compteur, int i)
{
	int j;

	if (i > 0)
	{
		result[--compteur] = 'x';
		result[--compteur] = '0';
	}
	if (i == 2)
	{
		j = compteur;
		while (result[compteur])
		{
			if (result[compteur] >= 'a' && result[compteur] <= 'z')
				result[compteur] = ft_toupper(result[compteur]);
			compteur++;
		}
		ft_putstr(result + j);
	}
	else
		ft_putstr(result + compteur);
	free(result);
}

void		ft_putaddress(void *address, int i)
{
	unsigned long	nbr;
	int				compteur;
	char			*str;
	char			*result;

	compteur = 18;
	if (i > 0)
		nbr = (unsigned long)address;
	else
		nbr = (unsigned int)address;
	if (nbr == 0)
	{
		ft_putstr("0x0");
		return ;
	}
	str = "0123456789abcdef";
	result = malloc(sizeof(char) * compteur + 1);
	result[compteur] = '\0';
	while (nbr > 0)
	{
		compteur--;
		result[compteur] = str[nbr % 16];
		nbr /= 16;
	}
	ft_print(result, compteur, i);
}
