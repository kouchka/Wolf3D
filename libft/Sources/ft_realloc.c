/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:22:16 by allallem          #+#    #+#             */
/*   Updated: 2017/12/15 13:29:24 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, size_t lenstr, size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!str && lenstr)
		return (NULL);
	if (!(new = ft_memalloc(lenstr + size + 1)))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (new[i])
	{
		new[i] = 0;
		i++;
	}
	free(str);
	return (new);
}
