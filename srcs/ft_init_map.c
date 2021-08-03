/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:32:18 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:32:19 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_inited(t_all *stock)
{
	if (stock->n_path == NULL || stock->s_path == NULL
		|| stock->e_path == NULL || stock->w_path == NULL
		|| stock->sprite_path == NULL || stock->map == NULL)
	{
		printf("Error: your image are not correct!!!!\n");
		if (stock->n_path != NULL)
			free(stock->n_path);
		else if (stock->s_path != NULL)
			free(stock->s_path);
		else if (stock->e_path != NULL)
			free(stock->e_path);
		else if (stock->w_path != NULL)
			free(stock->w_path);
		else if (stock->sprite_path != NULL)
			free(stock->sprite_path);
		return (0);
	}
	return (1);
}

double	find_pos(char **map, int flag)
{
	char	*temp;
	char	**save_map;

	save_map = map;
	while (map != NULL)
	{
		temp = *map;
		while (finder("NSEW", *temp) == 0 && *temp != '\0')
			temp++;
		if (finder("NSEW", *temp) == 1)
			break ;
		map++;
	}
	if (flag == 0)
		return (temp - *map + 0.5);
	else
		return (map - save_map + 0.5);
}

void	other_init(t_all *all)
{
	all->key_w = -1;
	all->key_left = -1;
	all->key_rigth = -1;
	all->key_rr = -1;
	all->key_rl = -1;
	all->x = 0;
	all->stepx = 0;
	all->stepy = 0;
	all->raydirx = 0;
	all->raydiry = 0;
	all->deltadistx = 0;
	all->deltadisty = 0;
	all->perpwalldist = 0;
	all->sidedistx = 0;
	all->sidedisty = 0;
	all->mapx = (int)all->posx;
	all->mapy = (int)all->posy;
	all->mspeed = 0.06;
	all->rspeed = 0.06;
	all->zbuffer = (double *)malloc(sizeof(double) * all->width);
	if (!all->zbuffer)
		all->zbuffer = NULL;
}

static void	init_continue(t_all *all, char player)
{
	int	k;
	int	i;
	int	j;

	k = -1;
	i = -1;
	while (++k < all->list->length - all->list->end)
		all->map[k] = malloc(sizeof(char) * (all->list->max));
	while (++i < all->list->length - all->list->end)
	{
		j = -1;
		while (++j < all->list->max)
			all->map[i][j] = all->list->map[i][j];
	}
	if (ft_inited(all) == 0)
		free_all(all);
	all->posx = find_pos(all->map, 0);
	all->posy = find_pos(all->map, 1);
	all->dirx = init_dir(player, 0);
	all->diry = init_dir(player, 1);
	all->planx = init_plane(player, 0);
	all->plany = init_plane(player, 1);
	all->camerax = 0;
	all->key_back = -1;
	other_init(all);
}

t_all	*init_all(t_param *list, char **s)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	if (list->width > 2560)
		list->width = 2560;
	if (list->heigth > 1440)
		list->heigth = 1440;
	all->width = list->width;
	all->heigth = list->heigth;
	all->list = list;
	all->n_path = ft_strdup(list->no);
	all->s_path = ft_strdup(list->so);
	all->e_path = ft_strdup(list->ea);
	all->w_path = ft_strdup(list->we);
	all->sprite_path = ft_strdup(list->s);
	all->floor_color = list->f;
	all->ceiling_color = list->c;
	all->map = malloc(sizeof(char *) * (list->length - list->end));
	init_continue(all, list->player);
	return (all);
}
