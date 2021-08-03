/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:34:11 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:34:12 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	drawing_ext(t_all *all, int x_stripe, t_spr *sp, int x_text)
{
	int	color;
	int	stripey;
	int	textx;

	if (sp->transformy > 0 && x_stripe > 0 && x_stripe < all->width
		&& sp->transformy < all->zbuffer[x_stripe])
	{
		stripey = sp->drawstarty;
		while (stripey < sp->drawendy)
		{
			color = stripey * 256 - all->heigth * 128 + sp->spriteh * 128;
			textx = ((color * all->text_sp->height) / sp->spriteh) / 256;
			color = (int)all->text_sp->data[all->text_sp->width
				* textx + x_text];
			color = color & 0xFFFFFFF;
			if ((color & 0x00FFFFFF) != 0)
				all->img->data[stripey * all->img->width + x_stripe] = color;
			stripey++;
		}
	}
}

void	drawing(t_all *all, t_spr *sp)
{
	int		textx;
	int		stripex;
	int		y;

	stripex = sp->drawstartx;
	while (stripex < sp->drawendx)
	{
		textx = (int)(256 * (stripex - (-sp->spritew / 2 + sp->spritescreenx))
				* all->text_sp->width / sp->spritew) / 256;
		if (sp->transformy > 0 && stripex > 0 && stripex < all->width
			&& sp->transformy < all->zbuffer[stripex])
		{
			drawing_ext(all, stripex, sp, textx);
			y++;
		}
		stripex++;
	}
}

void	drawing_calc(t_all *all, t_spr *sp)
{
	sp->drawstarty = (-sp->spriteh / 2 + all->heigth / 2);
	if (sp->drawstarty < 0)
		sp->drawstarty = 0;
	sp->drawendy = sp->spriteh / 2 + all->heigth / 2;
	if (sp->drawendy >= all->heigth)
		sp->drawendy = all->heigth - 1;
	sp->drawstartx = -sp->spritew / 2 + sp->spritescreenx;
	if (sp->drawstartx < 0)
		sp->drawstartx = 0;
	sp->drawendx = sp->spritew / 2 + sp->spritescreenx;
	if (sp->drawendx >= all->width)
		sp->drawendx = all->width - 1;
}

void	calc(t_all *all, t_spr *sp, int i)
{
	double	invdet;
	double	spritex;
	double	spritey;
	double	transformx;
	double	count;

	spritex = all->sprites_coords[i].x - all->posx;
	spritey = all->sprites_coords[i].y - all->posy;
	invdet = 1.0 / (all->planx * all->diry - all->dirx * all->plany);
	transformx = invdet * (all->diry * spritex - all->dirx * spritey);
	sp->transformy = invdet * (-all->plany * spritex + all->planx * spritey);
	sp->spritescreenx = (int)((all->width / 2) * (1 + transformx
				/ sp->transformy));
	sp->spriteh = abs((int)(all->heigth / (sp->transformy)));
	sp->spritew = abs((int)(all->heigth / (sp->transformy)));
}

void	draw_sprites(t_all *all)
{
	int		i;
	t_spr	sprite;

	i = 0;
	sort_sprites(all);
	while (i < all->n_sprites)
	{
		calc(all, &sprite, i);
		drawing_calc(all, &sprite);
		drawing(all, &sprite);
		i++;
	}
}
