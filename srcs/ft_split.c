/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:08:52 by pyamcha           #+#    #+#             */
/*   Updated: 2020/11/25 19:45:33 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**ft_strfree(char **s)
{
	while (s++)
		free(*s);
	free(*s);
	free(s);
	return (NULL);
}

static size_t	ft_counter(char const *s, char c)
{
	size_t	k;
	size_t	i;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\0')
			k++;
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i] != '\0')
			k++;
	}
	return (k);
}

static char	**ft_perv(char const *s, char **str, char c)
{
	char	**p;
	size_t	i;
	size_t	j;

	p = str;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			j = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			*p++ = ft_substr(s, j, i - j);
			if (!p)
				return (ft_strfree(str));
		}
	}
	*p = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!str)
		return (NULL);
	return (ft_perv(s, str, c));
}
