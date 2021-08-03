/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:08:52 by pyamcha           #+#    #+#             */
/*   Updated: 2020/11/22 18:48:34 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*check(size_t beg, size_t end, char const *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(*s1) * (end - beg + 1));
	if (!str)
		return (NULL);
	while (beg < end)
	{
		str[i] = s1[beg];
		beg++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	beg;
	size_t	end;

	i = 0;
	beg = 0;
	if (!s1)
		return (NULL);
	while (s1[beg] && ft_char_set(s1[beg], set))
		beg++;
	end = ft_strlen(s1);
	while (end > beg && ft_char_set(s1[end - 1], set))
		end--;
	return (check(beg, end, s1));
}
