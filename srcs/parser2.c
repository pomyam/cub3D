/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:35:46 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:35:49 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_we(char *line, t_param *list)
{
	int		i;
	int		k;
	char	**s;

	i = 0;
	k = 0;
	s = ft_split(line, ' ');
	while (s[i])
		i++;
	if (i != 2 || list->we != NULL)
		ft_errors(8);
	list->we = ft_strdup(s[1]);
	while (k < i)
	{
		free((void *)s[k]);
		k++;
	}
	free((void *)s);
}

void	ft_check_f(char *line, t_param *list)
{
	int		i;

	i = 2;
	list->red = 0;
	list->g = 0;
	list->b = 0;
	i = ft_check_f_or_c(line, list, i, 1);
	i = ft_check_f_or_c(line, list, i, 2);
	i = ft_check_f_or_c(line, list, i, 3);
	while (line[i])
	{
		if (line[i] != ' ')
			ft_errors(4);
		i++;
	}
	if (list->red < 0 || list->red > 255 || list->g < 0
		|| list->g > 255 || list->b < 0 || list->b > 255)
		ft_errors(4);
	list->f = list->red * pow(16, 4) + list->g * pow(16, 2) + list->b;
}

void	ft_check_c(char *line, t_param *list)
{
	int		i;

	i = 2;
	list->red = 0;
	list->g = 0;
	list->b = 0;
	i = ft_check_f_or_c(line, list, i, 1);
	i = ft_check_f_or_c(line, list, i, 2);
	i = ft_check_f_or_c(line, list, i, 3);
	while (line[i])
	{
		if (line[i] != ' ')
			ft_errors(4);
		i++;
	}
	if (list->red < 0 || list->red > 255 || list->g < 0
		|| list->g > 255 || list->b < 0 || list->b > 255)
		ft_errors(4);
	list->c = list->red * pow(16, 4) + list->g * pow(16, 2) + list->b;
}

void	ft_check_s(char *line, t_param *list)
{
	int		i;
	int		k;
	char	**s;

	i = 0;
	k = 0;
	s = ft_split(line, ' ');
	while (s[i])
		i++;
	if (i != 2 || list->s != NULL)
		ft_errors(8);
	list->s = ft_strdup(s[1]);
	while (k < i)
	{
		free((void *)s[k]);
		k++;
	}
	free((void *)s);
}

int	ft_checking_two(char *line, t_param *list, int j)
{
	int	count;

	count = 0;
	if (line[j] == 'W' && line[j + 1] == 'E' && line[j + 2] == ' ')
	{
		ft_check_we(line, list);
		count++;
	}
	else if (line[j] == 'C' && line[j + 1] == ' ')
	{
		ft_check_c(line, list);
		count++;
	}
	else if (line[j] == 'F' && line[j + 1] == ' ')
	{
		ft_check_f(line, list);
		count++;
	}
	else if (line[j] == 'S' && line[j + 1] == ' ')
	{
		ft_check_s(line, list);
		count++;
	}
	return (count);
}
