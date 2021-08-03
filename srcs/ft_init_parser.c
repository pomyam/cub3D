/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:32:27 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:32:28 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_f_or_c(char *line, t_param *list, int i, int flag)
{
	int	temp;
	int	n;

	while (line[i] == ' ')
		i++;
	temp = i;
	n = 0;
	while (line[i] >= '0' && line[i] <= '9' && flag < 256)
	{
		n = n * 10 + (line[i] - '0');
		i++;
	}
	if (i == temp)
		ft_errors(4);
	if (line[i] == ',' && flag == 3)
		ft_errors(4);
	if (line[i] == ',')
		i++;
	if (flag == 1)
		list->red = n;
	else if (flag == 2)
		list->g = n;
	else
		list->b = n;
	return (i);
}

void	init_list(t_param **list)
{
	*list = malloc(sizeof(t_param));
	if (!*list)
		ft_errors(7);
	(*list)->width = 0;
	(*list)->heigth = 0;
	(*list)->r = '\0';
	(*list)->no = NULL;
	(*list)->ea = NULL;
	(*list)->so = NULL;
	(*list)->s = NULL;
	(*list)->we = NULL;
	(*list)->f = -1;
	(*list)->c = -1;
	(*list)->save = 0;
	(*list)->end = 0;
	(*list)->length = 0;
	(*list)->flag = 0;
	(*list)->max = 0;
	(*list)->player = '\0';
	(*list)->red = 0;
	(*list)->g = 0;
	(*list)->b = 0;
}
