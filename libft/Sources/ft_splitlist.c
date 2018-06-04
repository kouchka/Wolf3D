/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:57:34 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 16:46:42 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strduplist(char const *s, int start, int len)
{
	char	*content;
	int		i;

	i = 0;
	content = (char*)malloc(sizeof(char) * len + 1);
	while ((len > i) && s[start])
	{
		content[i] = s[start];
		start++;
		i++;
	}
	content[len] = '\0';
	return (content);
}

static t_list	*ft_filllist(char const *s, char c, t_list *head)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = head;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (j > 0)
		{
			tmp->content = ft_strduplist(s, i - j, j);
			tmp = tmp->next;
		}
		if (s[i])
			i++;
	}
	return (head);
}

static t_list	*ft_malloclist(char const *s, char c, t_list *head)
{
	t_list	*point;
	t_list	*tmp;
	int		i;

	tmp = head;
	i = 0;
	if (s[0] != c)
		i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
		{
			if (!(point = malloc(sizeof(t_list))))
				return (NULL);
			point->next = NULL;
			tmp->next = point;
			tmp = tmp->next;
		}
		i++;
	}
	return (head);
}

t_list			*ft_splitlist(char *tab, char c)
{
	t_list *head;
	t_list *list;

	if (!tab)
		return (NULL);
	if (!(head = malloc(sizeof(t_list))))
		return (NULL);
	head->next = NULL;
	list = head;
	ft_malloclist(tab, c, list);
	ft_filllist(tab, c, list);
	if (head->content == NULL)
		return (NULL);
	return (head);
}
