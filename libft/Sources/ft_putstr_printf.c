/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:59:46 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:43:21 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_printf(char const *str, t_pfspe *p)
{
	int		i;
	char	*nul;

	nul = "(null)";
	i = 0;
	if (!str)
	{
		while (nul[i])
		{
			ft_check_buffer(p, nul[i]);
			i++;
		}
		return ;
	}
	while (str[i])
	{
		ft_check_buffer(p, str[i]);
		i++;
	}
}
