/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:40:18 by allallem          #+#    #+#             */
/*   Updated: 2017/11/25 09:27:27 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_fillstr(char *dest, int count, int n)
{
	while (n > 9 || n < -9)
	{
		if (n < 0)
			dest[count] = (-(n % 10) + 48);
		else
			dest[count] = ((n % 10) + 48);
		count--;
		n = n / 10;
	}
	if (n < 0)
	{
		dest[count] = (-(n % 10) + 48);
		dest[0] = 45;
	}
	else
		dest[count] = ((n % 10) + 48);
	return (dest);
}

static int		ft_countoctint(int n)
{
	int count;

	if (n == 0)
		return (2);
	count = 0;
	if (n < 0)
		count++;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		count;

	count = ft_countoctint(n);
	if (!(dest = (char*)malloc(sizeof(char) * count)))
		return (NULL);
	dest[count] = '\0';
	if (n == 0)
	{
		dest[0] = '0';
		return (dest);
	}
	count--;
	ft_fillstr(dest, count, n);
	return (dest);
}
