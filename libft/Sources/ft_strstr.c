/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:54:16 by allallem          #+#    #+#             */
/*   Updated: 2017/11/22 14:57:09 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *dest, char const *pattern)
{
	size_t i;
	size_t j;

	i = 0;
	if (pattern[0] == '\0')
		return ((char*)dest);
	while (dest[i])
	{
		j = 0;
		while (dest[i + j] == pattern[j] && pattern[j])
			j++;
		if ((dest[i + (j - 1)] == pattern[j - 1]) && pattern[j] == '\0')
			return ((char *)dest + i);
		i++;
	}
	return (NULL);
}
