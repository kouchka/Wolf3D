/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:00:18 by allallem          #+#    #+#             */
/*   Updated: 2017/11/22 14:30:35 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t			i;
	unsigned char	*pts1;
	unsigned char	*pts2;

	pts1 = (unsigned char*)s1;
	pts2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((pts1[i] == pts2[i]) && (i < (n - 1)))
		i++;
	return (pts1[i] - pts2[i]);
}
