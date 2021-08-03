/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:10:56 by pyamcha           #+#    #+#             */
/*   Updated: 2021/04/23 20:10:58 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_empty_line(char **s, int i)
{
	while (s[i][0] == '\n' || s[i][0] == '\0')
		i++;
	return (i);
}

void	dodelat_map(char **s, t_param *list, int len)
{
	int		i;
	int		j;
	char	**map;

	i = list->end - 1;
	map = malloc(sizeof(char *) * (list->length));
	while (++i < list->length)
	{
		map[i] = ft_calloc(list->max, sizeof(char));
		j = 0;
		while (j < list->max)
		{
			map[i][j] = s[i][j];
			if (s[i][j] == '\0' || s[i][j] == '\n')
			{
				map[i][j] = ' ';
				while (++j < list->max)
					map[i][j] = ' ';
				map[i][j] = '\0';
			}
			j++;
		}
	}
	ft_analyse_map(map, list, len);
}

void	ft_check_params(t_param *list, char **s, int len, int i)
{
	list->end = ft_check_empty_line(s, i);
	if (list->r == '\0' || list->no == NULL || list->ea == NULL
		|| list->so == NULL || list->we == NULL || list->c == -1)
		ft_errors(8);
	else if (list->f == -1 || list->s == NULL)
		ft_errors(8);
	dodelat_map(s, list, len);
}

void	ft_parser(char **s, t_param *list, int len)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (count != 8 && s[i])
	{
		j = 0;
		if (!(s[i]))
			ft_errors(8);
		while (s[i][j] == ' ')
			j++;
		count += ft_checking_one(s[i], list, j);
		if (ft_strnstr(s[i], "R", 20) == 0 && ft_strnstr(s[i], "\0", 20) == 0
			&& ft_strncmp("NO", s[i], 1) != 0 && ft_strnstr(s[i], "F", 20) == 0
			&& ft_strnstr(s[i], "C", 20) == 0 && ft_strncmp("SO", s[i], 10) != 0
			&& ft_strnstr(s[i], "S", 20) == 0 && ft_strncmp("EA", s[i], 10) != 0
			&& ft_strncmp("WE", s[i], 10) != 0
			&& ft_strnstr(s[i], "\n", 20) == 0)
			ft_errors(8);
		i++;
	}
	ft_check_params(list, s, len, i);
}
