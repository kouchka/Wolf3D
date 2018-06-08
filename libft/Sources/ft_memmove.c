/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:37:35 by allallem          #+#    #+#             */
/*   Updated: 2017/11/22 11:10:29 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, void const *src, size_t n)
{
	size_t				i;
	unsigned char		*ptdest;
	unsigned char const	*ptsrc;

	i = 0;
	ptsrc = src;
	ptdest = dest;
	if (ptsrc < ptdest)
	{
		while (n > 0)
		{
			n--;
			ptdest[n] = ptsrc[n];
		}
	}
	else
		ft_memcpy(ptdest, ptsrc, n);
	return ((unsigned char*)dest);
}
