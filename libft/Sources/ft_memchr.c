/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:49:47 by allallem          #+#    #+#             */
/*   Updated: 2017/11/22 10:16:13 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pts;

	pts = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (pts[i] == (unsigned char)c)
			return (&pts[i]);
		i++;
	}
	return (NULL);
}
