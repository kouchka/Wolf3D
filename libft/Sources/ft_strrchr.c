/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:44:26 by allallem          #+#    #+#             */
/*   Updated: 2017/11/22 15:36:43 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s1, int c)
{
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	i = 0;
	if (c == '\0')
		return ((char *)s1 + ft_strlen(s1));
	while (s1[i])
	{
		if (s1[i] == c)
		{
			k++;
			j = i;
			i++;
		}
		while (s1[i] != c && s1[i])
			i++;
	}
	if (i > 0 && k > 0)
		return ((char *)s1 + j);
	return (0);
}
