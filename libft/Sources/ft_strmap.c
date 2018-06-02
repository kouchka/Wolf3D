/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:09:41 by allallem          #+#    #+#             */
/*   Updated: 2017/11/25 08:36:45 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		dest[i] = (*f)(s[i]);
		i++;
	}
	dest[ft_strlen(s)] = '\0';
	return (dest);
}
