/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 09:10:45 by allallem          #+#    #+#             */
/*   Updated: 2017/11/23 10:46:15 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_filltab(char **tab, char const *s, char c, size_t count)
{
	size_t	i;
	int		j;
	int		e;

	e = 0;
	i = 0;
	while (s[e] && count > i)
	{
		j = 0;
		while (s[e] == c)
			e++;
		while (s[e] != c && s[e])
		{
			tab[i][j] = s[e];
			j++;
			e++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

static char		**ft_mallocstr(char **tab, char const *s, char c)
{
	int i;
	int j;
	int e;

	i = 0;
	e = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i])
		{
			j++;
			i++;
		}
		while (s[i] == c)
			i++;
		if (j > 0)
		{
			if (!(tab[e] = (char*)malloc(sizeof(char) * (j + 1))))
				return (NULL);
			e++;
		}
	}
	return (tab);
}

static size_t	ft_strcounts(char const *s, char c)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	if (s[0] != c && s[i])
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c && s[i])
			count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**tab;

	if (!s)
		return (NULL);
	count = ft_strcounts(s, c);
	if (!(tab = (char**)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = 0;
	if (count > 0)
	{
		ft_mallocstr(tab, s, c);
		ft_filltab(tab, s, c, count);
	}
	return (tab);
}
