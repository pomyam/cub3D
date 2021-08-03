/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:35:59 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:36:00 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_r_index(char *line, int i)
{
	while (line[i] == ' ' || line[i] == 'R')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	return (i);
}

int	find_r_h(char *line, int i)
{
	long	nbr;

	nbr = 0;
	while (line[i] == 'R' || line[i] == ' ' || line[i] == '\0')
		i++;
	while ((line[i] >= '0' && line[i] <= '9') && line[i] != '\0')
	{
		if (nbr > 1440)
			return (1440);
		else
			nbr = nbr * 10 + (line[i] - '0');
		i++;
	}
	return (nbr);
}

int	find_r_w(char *line, int i)
{
	long	nbr;

	nbr = 0;
	while (line[i] == 'R' || line[i] == ' ' || line[i] == '\0')
		i++;
	while ((line[i] >= '0' && line[i] <= '9') && line[i] != '\0')
	{
		if (nbr > 2560)
			return (2560);
		nbr = nbr * 10 + (line[i] - '0');
		i++;
	}
	return (nbr);
}

void	ft_check_r(char *line, t_param *list)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	list->width = find_r_w(line, i);
	count += 1;
	i = find_r_index(line, i);
	list->heigth = find_r_h(line, i);
	count += 1;
	i = find_r_index(line, i);
	while (line[i])
	{
		if (line[i] != ' ' || line[i] == ',')
			ft_errors(8);
		i++;
	}
	list->r += 1;
	if (list->r > 1 || (list->width <= 0 || list->heigth <= 0))
		ft_errors(8);
	if (list->width > 0 && list->width < 150)
		list->width = 150;
	if (list->heigth > 0 && list->heigth < 150)
		list->heigth = 150;
}
