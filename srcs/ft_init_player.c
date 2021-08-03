/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:32:39 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:32:41 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	init_dir(char player, int flag)
{
	if (player == 'N' && flag == 0)
		return (0);
	else if (player == 'S' && flag == 0)
		return (0);
	else if (player == 'E' && flag == 0)
		return (1);
	else if (player == 'W' && flag == 0)
		return (-1);
	else if (player == 'N' && flag == 1)
		return (-1);
	else if (player == 'S' && flag == 1)
		return (1);
	else if (player == 'E' && flag == 1)
		return (0);
	else if (player == 'W' && flag == 1)
		return (0);
	return (0);
}

double	init_plane(char player, int flag)
{
	if (player == 'N' && flag == 0)
		return (0.66);
	if (player == 'S' && flag == 0)
		return (-0.66);
	if (player == 'E' && flag == 0)
		return (0);
	if (player == 'W' && flag == 0)
		return (0);
	if (player == 'N' && flag == 1)
		return (0);
	if (player == 'S' && flag == 1)
		return (0);
	if (player == 'E' && flag == 1)
		return (0.66);
	if (player == 'W' && flag == 1)
		return (-0.66);
	return (0);
}
