/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_one_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:31:19 by allallem          #+#    #+#             */
/*   Updated: 2018/01/04 15:56:08 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_one_more(char const *s, int c)
{
	int i;

	i = 0;
	while ((s[i] != c) && s[i])
		i++;
	if (s[i] == c)
		return ((char *)s + (i + 1));
	return (NULL);
}
