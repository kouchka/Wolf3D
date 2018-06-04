/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:49:54 by allallem          #+#    #+#             */
/*   Updated: 2017/11/22 10:20:43 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	int				i;
	unsigned char	*pts1;
	unsigned char	*pts2;

	pts1 = (unsigned char*)s1;
	pts2 = (unsigned char*)s2;
	i = 0;
	while (pts1[i] == pts2[i] && pts1[i] && pts2[i])
		i++;
	return (pts1[i] - pts2[i]);
}
