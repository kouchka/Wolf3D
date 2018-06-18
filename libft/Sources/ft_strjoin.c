/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 07:42:54 by allallem          #+#    #+#             */
/*   Updated: 2017/12/15 18:35:20 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	len = j + ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < j)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < (len - i))
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
