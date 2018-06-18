/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 07:05:58 by allallem          #+#    #+#             */
/*   Updated: 2017/11/23 10:46:22 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char const *pts1;
	char const *pts2;

	if (!s1 || !s2)
		return (0);
	pts1 = s1;
	pts2 = s2;
	if ((ft_strncmp(pts1, pts2, n) == 0))
		return (1);
	return (0);
}
