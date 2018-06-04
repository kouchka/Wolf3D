/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 08:34:51 by allallem          #+#    #+#             */
/*   Updated: 2017/11/23 10:46:04 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strstart(char const *s)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		if ((s[i]) == ' ')
			count++;
		i++;
	}
	if (count == 0)
		return (0);
	return (i);
}

static size_t	ft_strlenspe(char const *s, size_t i)
{
	size_t j;
	size_t count;

	count = 0;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > 0)
	{
		if (s[j] == ' ')
			count++;
		j--;
	}
	if ((j == ft_strlen(s) - 1 || count == 0) && i == 0)
		return (0);
	if (j == 0)
		return (0);
	return (j - i + 1);
}

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;
	char	*dest;

	if (!s)
		return (NULL);
	start = ft_strstart(s);
	len = ft_strlenspe(s, start);
	if (len == 0 && start == 0)
		return (ft_strdup(s));
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(dest, &s[start], len + 1);
	dest[len] = '\0';
	return (dest);
}
