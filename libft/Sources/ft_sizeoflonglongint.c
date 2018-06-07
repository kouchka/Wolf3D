/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeofintmax_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:48:50 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:43:30 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizeoflonglongint(long long int size, int precision)
{
	int i;

	i = 0;
	(size < 0 && precision == 0) ? i++ : 0;
	while (size > 9 || size < -9)
	{
		size = size / 10;
		i++;
	}
	i++;
	return (i);
}
