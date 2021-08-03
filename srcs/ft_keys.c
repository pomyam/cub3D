/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:32:51 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:32:53 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_background(t_all *all)
{
	int	*i;
	int	*floor;
	int	*ceiling;

	i = all->img->data;
	floor = (all->img->width * all->img->height) + i;
	ceiling = ((all->img->width * all->img->height) / 2) + i;
	while (i < ceiling)
	{
		*i = all->ceiling_color;
		i++;
	}
	while (i < floor)
	{
		*i = all->floor_color;
		i++;
	}
}

int	rendering(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	all->img = my_mlx_new_image(all->mlx, all->win, all->width, all->heigth);
	if (!all->img)
	{
		free_all(all);
		ft_errors(15);
	}
	movings_player(all);
	draw_background(all);
	perform_raycasting(all);
	draw_sprites(all);
	mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
	mlx_destroy_image(all->img->mlx, all->img->img);
	free(all->img);
	return (0);
}

int	key_released(int keycode, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (keycode == K_ESC)
		exit(0);
	else if (keycode == K_W)
		all->key_w = 0;
	else if (keycode == K_A)
		all->key_left = 0;
	else if (keycode == K_S)
		all->key_back = 0;
	else if (keycode == K_D)
		all->key_rigth = 0;
	else if (keycode == ARRL)
		all->key_rr = 0;
	else if (keycode == ARRR)
		all->key_rl = 0;
	return (1);
}

int	key_pressed(int keycode, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (keycode == K_W)
		all->key_w = 1;
	else if (keycode == K_A)
		all->key_left = 1;
	else if (keycode == K_S)
		all->key_back = 1;
	else if (keycode == K_D)
		all->key_rigth = 1;
	else if (keycode == ARRL)
		all->key_rr = 1;
	else if (keycode == ARRR)
		all->key_rl = 1;
	else if (keycode == K_ESC)
	{
		free_all(all);
		exit(0);
	}
	return (1);
}
