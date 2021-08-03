/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:57:25 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/27 13:15:34 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ifn(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		index;
	int		jndex;

	index = 0;
	if (!s1 && !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	if (!index && s1)
	{
		index--;
		while (s1[++index] != '\0')
			s3[index] = s1[index];
	}
	jndex = -1;
	while (s2[++jndex] != '\0')
	{
		s3[index] = s2[jndex];
		index++;
	}
	s3[index] = '\0';
	free((char *)s1);
	return (s3);
}

char	*putsave(char *save)
{
	int		index;
	int		jndex;
	char	*new;

	index = 0;
	jndex = 0;
	if (!save)
		return (0);
	while (save[index] && save[index] != '\n')
		index++;
	if (!save[index])
	{
		free(save);
		return (0);
	}
	new = malloc(sizeof(char) * ((ft_strlen(save) - index) + 1));
	if (!new)
		return (0);
	index++;
	while (save[index])
		new[jndex++] = save[index++];
	new[jndex] = '\0';
	free(save);
	return (new);
}

char	*putline(char *str)
{
	int		index;
	char	*new;

	index = 0;
	if (!str)
		return (0);
	while (str[index] && str[index] != '\n')
		index++;
	new = malloc(sizeof(char) * (index + 1));
	if (!new)
		return (0);
	index = -1;
	while (str[++index] && str[index] != '\n')
		new[index] = str[index];
	new[index] = '\0';
	return (new);
}
