/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:31:31 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:31:35 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_vertical(t_all *s, int y_start, int y_end)
{
	int	color;

	if (s->hitside == 'N')
		color = BLUE;
	else if (s->hitside == 'S')
		color = RED;
	else if (s->hitside == 'E')
		color = GREEN;
	else if (s->hitside == 'W')
		color = YELLOW;
	while (y_start < y_end)
	{
		*(s->img->data + ((s->img->width) * y_start) + s->x) = color;
		y_start++;
	}
}

void	*side_texture(t_all *all)
{
	if (all->hitside == 'S')
		return (all->text_n);
	else if (all->hitside == 'N')
		return (all->text_s);
	else if (all->hitside == 'W')
		return (all->text_e);
	else if (all->hitside == 'E')
		return (all->text_w);
	return (NULL);
}

int	ft_color(t_all *all, int start, int lineheight)
{
	int		color;
	double	textx;
	double	texty;
	double	wallx;
	t_win	*texture;

	texture = side_texture(all);
	if (all->side == 0)
		wallx = all->posy + all->perpwalldist * all->raydiry;
	else
		wallx = all->posx + all->perpwalldist * all->raydirx;
	wallx -= floor((wallx));
	textx = (wallx * (double)(texture->width));
	if (all->side == 0 && all->raydirx > 0)
		textx = texture->width - textx - 1;
	if (all->side == 1 && all->raydiry < 0)
		textx = texture->width - textx - 1;
	color = start * 256 - all->heigth * 128 + lineheight * 128;
	texty = (color * texture->height / lineheight) / 256;
	color = texture->data[(int)(texty * texture->width + textx)];
	color = color & 0xFFFFFFF;
	return (color);
}

void	draw_texture(t_all *all, int start, int end, int lineheight)
{
	int	color;

	while (start < end)
	{
		color = ft_color(all, start, lineheight);
		all->img->data[(all->img->width * start) + all->x] = color;
		start++;
	}
}
