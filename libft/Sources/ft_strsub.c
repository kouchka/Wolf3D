/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 07:07:18 by allallem          #+#    #+#             */
/*   Updated: 2017/11/21 10:13:14 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ps;

	if (!s)
		return (NULL);
	ps = NULL;
	if (!(ps = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ps[len] = '\0';
	return (ft_strncpy(ps, &s[start], len));
}
