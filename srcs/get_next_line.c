/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:34:19 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/17 18:44:15 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check(int reader, char *buff)
{
	if (reader == -1)
	{
		free(buff);
		return (-1);
	}
	buff[reader] = '\0';
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;
	int			reader;

	reader = 1;
	if (fd < 0 || !line)
		return (-1);
	buff = malloc(1);
	if (!buff)
		return (-1);
	while (!ifn(save) && reader != 0)
	{
		reader = read(fd, buff, 1);
		if (check(reader, buff) == -1)
			return (-1);
		save = ft_strjoin(save, buff);
	}
	free(buff);
	*line = putline(save);
	save = putsave(save);
	if (reader == 0)
		return (0);
	return (1);
}
