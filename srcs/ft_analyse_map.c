/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:31:07 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:31:09 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_first(t_param *list, char **s, int i)
{
	int	j;

	if (i == list->end || i == list->length - 1)
	{
		j = 0;
		while (j < list->max)
		{
			if (s[i][j] != '1' && s[i][j] != ' ')
				ft_errors(9);
			j++;
		}
	}
}

void	ft_analyse_map(char **s, t_param *list, int len)
{
	int		k;

	k = -1;
	list->map = malloc(sizeof(char *) * (list->length - list->end));
	while (++k < list->length - list->end)
		list->map[k] = malloc(sizeof(char) * (list->max));
	ft_cycle(list, len, s);
	if (list->player == '\0')
		ft_errors(9);
	ft_create_my_map(s, list);
}
