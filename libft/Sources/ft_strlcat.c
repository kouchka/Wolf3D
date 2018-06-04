/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:40:50 by allallem          #+#    #+#             */
/*   Updated: 2017/11/22 17:26:57 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	i;
	int		n;
	size_t	lentot;

	i = 0;
	n = 0;
	lentot = ft_strlen(dest) + ft_strlen(src);
	while (dest[i])
		i++;
	while (src[n] && i < (size - 1) && size > 0)
		dest[i++] = src[n++];
	while (i < size)
		dest[i++] = '\0';
	if (size < ft_strlen(dest))
		return (size + ft_strlen((char*)src));
	return (lentot);
}
