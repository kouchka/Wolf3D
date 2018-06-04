/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:12:25 by allallem          #+#    #+#             */
/*   Updated: 2017/11/23 10:41:30 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *dest, char const *pattern, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (ft_strlen(pattern) == 0)
		return ((char *)dest);
	while (dest[i] && (i < n))
	{
		j = 0;
		while (dest[i + j] == pattern[j] && pattern[j] && (i + j) < n)
			j++;
		if ((dest[i + (j - 1)] == pattern[j - 1]) && pattern[j] == '\0')
			return ((char *)dest + i);
		i++;
	}
	return (NULL);
}
