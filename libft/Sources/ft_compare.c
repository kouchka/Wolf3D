/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:02:38 by allallem          #+#    #+#             */
/*   Updated: 2018/02/15 17:06:05 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_compare(char *str, char *pattern)
{
	int i;

	i = 0;
	if (str == NULL || pattern == NULL)
		return (0);
	while ((str[i] || pattern[i]) && str[i] == pattern[i])
		i++;
	if (pattern[i] == '\0' && pattern[i - 1] == str[i - 1])
		return (1);
	return (0);
}
