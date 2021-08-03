/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:32:04 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:32:06 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	side_between(t_all *all)
{
	if (all->raydiry < 0)
	{
		if (all->side == 0)
			return ('E');
		else
			return ('S');
	}
	else
	{
		if (all->side == 0)
			return ('E');
		else
			return ('N');
	}
}

char	cub_hitside(t_all *all)
{
	if (all->raydirx > 0)
	{
		if (all->raydiry < 0)
		{
			if (all->side == 0)
				return ('W');
			else
				return ('S');
		}
		else
		{
			if (all->side == 0)
				return ('W');
			else
				return ('N');
		}
	}
	return (side_between(all));
}
