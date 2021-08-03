/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:34:21 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:34:23 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_all_sprites(t_all *s)
{
	t_point	*spr;
	int		i;
	int		j;

	i = 0;
	s->sprites_coords = (t_point *)malloc(sizeof(t_point) * s->n_sprites);
	if (!s->sprites_coords)
		ft_errors(2);
	spr = s->sprites_coords;
	while (i < s->list->length - s->list->end)
	{
		j = 0;
		while (j < s->list->max - 1)
		{
			if (s->map[i][j] == '2')
			{
				spr->x = (double)(j + 0.5);
				spr->y = (double)(i + 0.5);
				spr++;
			}
			j++;
		}
		i++;
	}
}

void	n_sprites(t_all *all, char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < all->list->length - all->list->end)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	all->n_sprites = count;
}

static void	sort_sprites_bubble(t_all *all, double *distance)
{
	int		i;
	double	dist;
	t_point	coord;

	i = 1;
	while (i < all->n_sprites)
	{
		if (distance[i - 1] < distance[i])
		{
			dist = distance[i - 1];
			distance[i - 1] = distance[i];
			distance[i] = dist;
			coord = all->sprites_coords[i - 1];
			all->sprites_coords[i - 1] = all->sprites_coords[i];
			all->sprites_coords[i] = coord;
			i = 1;
		}
		else
			i++;
	}
}

void	sort_sprites(t_all *all)
{
	int		i;
	double	*distance;

	i = 0;
	distance = (double *)malloc(sizeof(double) * all->n_sprites);
	if (!distance)
		return ;
	while (i < all->n_sprites)
	{
		distance[i] = pow(all->posx - all->sprites_coords[i].x, 2)
			+ pow(all->posy - all->sprites_coords[i].y, 2);
		i++;
	}
	sort_sprites_bubble(all, distance);
	free(distance);
}
