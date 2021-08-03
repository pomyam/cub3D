/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:33:46 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:33:47 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_wall(t_all *all)
{
	int		drawend;
	int		drawstart;
	int		lineheight;

	lineheight = (int)(all->heigth / all->perpwalldist);
	drawstart = -lineheight / 2 + all->heigth / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + all->heigth / 2;
	if (drawend >= all->heigth)
		drawend = all->heigth - 1;
	draw_vertical(all, drawstart, drawend);
	draw_texture(all, drawstart, drawend, lineheight);
}

void	throw_rays(t_all *all)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->sidedistx < all->sidedisty)
		{
			all->sidedistx += all->deltadistx;
			all->mapx += all->stepx;
			all->side = 0;
		}
		else
		{
			all->sidedisty += all->deltadisty;
			all->mapy += all->stepy;
			all->side = 1;
		}
		if (all->map[all->mapy][all->mapx] == '1')
			hit = 1;
	}
}

void	set_rays(t_all *all)
{
	all->camerax = 2 * all->x / (double)(all->width) - 1;
	all->raydirx = all->dirx + all->planx * all->camerax;
	all->raydiry = all->diry + all->plany * all->camerax;
	all->deltadistx = fabs(1 / all->raydirx);
	all->deltadisty = fabs(1 / all->raydiry);
	if (all->raydirx < 0)
	{
		all->stepx = -1;
		all->sidedistx = (all->posx - all->mapx) * all->deltadistx;
	}
	else
	{
		all->stepx = 1;
		all->sidedistx = (all->mapx + 1.0 - all->posx) * all->deltadistx;
	}
	if (all->raydiry < 0)
	{
		all->stepy = -1;
		all->sidedisty = (all->posy - all->mapy) * all->deltadisty;
	}
	else
	{
		all->stepy = 1;
		all->sidedisty = (all->mapy + 1.0 - all->posy) * all->deltadisty;
	}
}

void	perform_raycasting(t_all *all)
{
	while (all->x < all->width)
	{
		set_rays(all);
		throw_rays(all);
		if (all->side == 0)
			all->perpwalldist = (all->mapx - all->posx + (1 - all->stepx)
					/ 2) / all->raydirx;
		else
			all->perpwalldist = (all->mapy - all->posy + (1 - all->stepy)
					/ 2) / all->raydiry;
		all->hitside = cub_hitside(all);
		draw_wall(all);
		all->zbuffer[all->x] = all->perpwalldist;
		all->x++;
		all->mapx = (int)all->posx;
		all->mapy = (int)all->posy;
	}
	all->x = 0;
}
