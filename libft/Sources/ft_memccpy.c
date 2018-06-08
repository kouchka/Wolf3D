/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:23 by allallem          #+#    #+#             */
/*   Updated: 2017/11/22 16:53:24 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;
	unsigned char	cc;

	cc = c;
	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	i = 0;
	if (!n)
		return (NULL);
	while ((i < n) && (i == 0 || src2[i - 1] != cc))
	{
		dest2[i] = src2[i];
		i++;
	}
	if ((src2[i - 1] == cc) && i > 0)
		return (&dest2[i]);
	return (NULL);
}
