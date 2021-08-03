/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:35:38 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:35:40 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_no(char *line, t_param *list)
{
	int		i;
	int		k;
	char	**s;

	i = 0;
	k = 0;
	s = ft_split(line, ' ');
	while (s[i])
		i++;
	if (i != 2 || list->no != NULL)
		ft_errors(8);
	list->no = ft_strdup(s[1]);
	while (k < i)
	{
		free((void *)s[k]);
		k++;
	}
	free((void *)s);
}

void	ft_check_ea(char *line, t_param *list)
{
	int		i;
	int		k;
	char	**s;

	i = 0;
	k = 0;
	s = ft_split(line, ' ');
	while (s[i])
		i++;
	if (i != 2 || list->ea != NULL)
		ft_errors(8);
	list->ea = ft_strdup(s[1]);
	while (k < i)
	{
		free((void *)s[k]);
		k++;
	}
	free((void *)s);
}

void	ft_check_so(char *line, t_param *list)
{
	int		i;
	int		k;
	char	**s;

	i = 0;
	k = 0;
	s = ft_split(line, ' ');
	while (s[i])
		i++;
	if (i != 2 || list->so != NULL)
		ft_errors(8);
	list->so = ft_strdup(s[1]);
	while (k < i)
	{
		free((void *)s[k]);
		k++;
	}
	free((void *)s);
}

int	checker(int count, char line)
{
	if (count > 0)
		return (count);
	else if ((line == '\0' || line == '\n') && count == 0)
		return (count);
	else
		ft_errors(8);
	return (count);
}

int	ft_checking_one(char *line, t_param *list, int j)
{
	int	count;

	count = 0;
	if (line[j] == 'R' && line[j + 1] == ' ')
	{
		ft_check_r(line, list);
		count++;
	}
	else if (line[j] == 'N' && line[j + 1] == 'O' && line[j + 2] == ' ')
	{
		ft_check_no(line, list);
		count++;
	}
	else if (line[j] == 'E' && line[j + 1] == 'A' && line[j + 2] == ' ')
	{
		ft_check_ea(line, list);
		count++;
	}
	else if (line[j] == 'S' && line[j + 1] == 'O' && line[j + 2] == ' ')
	{
		ft_check_so(line, list);
		count++;
	}
	count += ft_checking_two(line, list, j);
	return (checker(count, line[j]));
}
