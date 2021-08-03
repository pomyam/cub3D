/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lodev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:33:04 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:33:05 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dop_free_all(t_all *all)
{
	int	i;

	i = -1;
	if (all->n_path)
		free(all->n_path);
	if (all->s_path)
		free(all->s_path);
	if (all->e_path)
		free(all->e_path);
	if (all->w_path)
		free(all->w_path);
	if (all->sprite_path)
		free(all->sprite_path);
	if (all->map)
	{
		while (++i < all->list->length - all->list->end)
			free((void *)all->map[i]);
	}
	free((void *)all->map);
	mlx_destroy_window(all->mlx, all->win);
}

void	free_all(t_all *all)
{
	if (all->text_n)
	{
		mlx_destroy_image(all->text_n->mlx, all->text_n->img);
		free(all->text_n);
	}
	if (all->text_s)
	{
		mlx_destroy_image(all->text_s->mlx, all->text_s->img);
		free(all->text_s);
	}
	if (all->text_e)
	{
		mlx_destroy_image(all->text_e->mlx, all->text_e->img);
		free(all->text_e);
	}
	if (all->text_w)
	{
		mlx_destroy_image(all->text_w->mlx, all->text_w->img);
		free(all->text_w);
	}
	dop_free_all(all);
}

void	check_texture(t_all *all)
{
	if (all->text_n == NULL || all->text_s == NULL
		|| all->text_e == NULL || all->text_w == NULL
		|| all->text_sp == NULL)
	{
		free_all(all);
		ft_errors(13);
	}
	if (all->zbuffer == NULL)
	{
		free_all(all);
		ft_errors(14);
	}
}

void	init_texture(t_all *all)
{
	all->text_n = my_mlx_xpm_to_img(all->mlx, all->n_path);
	all->text_s = my_mlx_xpm_to_img(all->mlx, all->s_path);
	all->text_e = my_mlx_xpm_to_img(all->mlx, all->e_path);
	all->text_w = my_mlx_xpm_to_img(all->mlx, all->w_path);
	all->text_sp = my_mlx_xpm_to_img(all->mlx, all->sprite_path);
	if (!all->text_n)
		all->text_n = NULL;
	if (!all->text_s)
		all->text_s = NULL;
	if (!all->text_e)
		all->text_e = NULL;
	if (!all->text_w)
		all->text_w = NULL;
	if (!all->text_sp)
		all->text_sp = NULL;
	check_texture(all);
}

void	ft_create_my_map(char **s, t_param *list)
{
	t_all	*all;

	all = init_all(list, s);
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->width, all->heigth, "pyamcha");
	if (!all->win)
		ft_errors(12);
	init_texture(all);
	n_sprites(all, all->map);
	init_all_sprites(all);
	if (list->save != 0)
		ft_bmp(all);
	else
	{
		mlx_loop_hook(all->mlx, &rendering, all);
		mlx_hook(all->win, 2, 0, &key_pressed, all);
		mlx_hook(all->win, 3, 0, &key_released, all);
		mlx_loop(all->mlx);
	}
	free_all(all);
}
