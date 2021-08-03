/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:30:39 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:30:44 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_analyse_dot(t_param *list, char **s, int i, int j)
{
	check_first(list, s, i);
	if ((s[i][j] == '0' || s[i][j] == '2') && i > 0)
	{
		if ((s[i + 1][j] != '1' && s[i + 1][j] != '2' && s[i + 1][j] != '0'
			&& s[i + 1][j] != 'N' && s[i + 1][j] != 'S' && s[i + 1][j] != 'W'
			&& s[i + 1][j] != 'E'))
			ft_errors(9);
		else if ((s[i - 1][j] != '1' && s[i - 1][j] != '2' && s[i - 1][j] != '0'
			&& s[i - 1][j] != 'N' && s[i - 1][j] != 'S' && s[i - 1][j] != 'W'
			&& s[i - 1][j] != 'E'))
			ft_errors(9);
		else if ((s[i][j + 1] != '1' && s[i][j + 1] != '2' && s[i][j + 1] != '0'
			&& s[i][j + 1] != 'N' && s[i][j + 1] != 'S' && s[i][j + 1] != 'W'
			&& s[i][j + 1] != 'E'))
			ft_errors(9);
		else if ((s[i][j - 1] != '1' && s[i][j - 1] != '2' && s[i][j - 1] != '0'
			&& s[i][j - 1] != 'N' && s[i][j - 1] != 'S' && s[i][j - 1] != 'W'
			&& s[i][j - 1] != 'E'))
			ft_errors(9);
	}
	if (list->flag == 1)
		list->flag = 0;
}

void	ft_analyse_player(char **s, t_param *list, int i, int j)
{
	if (s[i + 1][j] != '1' && s[i + 1][j] != '2' && s[i + 1][j] != '0')
		ft_errors(9);
	else if (s[i - 1][j] != '1' && s[i - 1][j] != '2' && s[i - 1][j] != '0')
		ft_errors(9);
	else if (s[i][j + 1] != '1' && s[i][j + 1] != '2' && s[i][j + 1] != '0')
		ft_errors(9);
	else if (s[i][j - 1] != '1' && s[i][j - 1] != '2' && s[i][j - 1] != '0')
		ft_errors(9);
	else if (list->player != '\0')
		ft_errors(9);
	else
		list->player = s[i][j];
}

void	ft_cycle_check(t_param *list, int i, int j, char **s)
{
	if (s[i][j] == 'N' || s[i][j] == 'S' || s[i][j] == 'E'
			|| s[i][j] == 'W')
		ft_analyse_player(s, list, i, j);
	else if (s[i][j] == '0' || s[i][j] == '1' ||
		s[i][j] == '2' || s[i][j] == ' ')
	{
		if (s[i][j + 1] == '\0')
			list->flag = 1;
		ft_analyse_dot(list, s, i, j);
	}
	else
		ft_errors(9);
}

void	ft_cycle_dop(t_param *list, int i, char **s, int k)
{
	int	j;

	j = 0;
	while (s[i][j] != '\0')
	{
		ft_cycle_check(list, i, j, s);
		list->map[k][j] = s[i][j];
		j++;
	}
	j++;
	if (j < list->max)
	{
		while (j < list->max)
		{
			list->map[k][j] = ' ';
			j++;
		}
	}
}

void	ft_cycle(t_param *list, int len, char **s)
{
	int		i;
	int		k;

	i = list->end - 1;
	k = 0;
	while (++i < len)
	{
		if (s[i][0] == '\0' || s[i][0] == '\n')
			ft_errors(9);
		ft_cycle_dop(list, i, s, k);
		k++;
	}
}
