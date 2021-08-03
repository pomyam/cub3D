/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:33:20 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:33:21 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_win	*my_mlx_xpm_to_img(void *mlx_ptr, char *path)
{
	t_win	*new;
	void	*temp;
	int		bpp;
	int		endian;
	int		trsh;

	bpp = 32;
	endian = 1;
	new = (t_win *)malloc(sizeof(t_win));
	if (!new)
		return (NULL);
	new->mlx = mlx_ptr;
	new->win = NULL;
	new->width = 0;
	new->height = 0;
	temp = mlx_xpm_file_to_image(mlx_ptr, path, &new->width, &new->height);
	if (!(temp))
	{
		free(new);
		return (NULL);
	}
	new->img = temp;
	new->data = (int *)mlx_get_data_addr(temp, &bpp, &trsh, &endian);
	return (new);
}

t_win	*my_mlx_new_image(void *mlx_ptr, void *win_ptr, int width, int height)
{
	t_win	*new;
	int		trsh;
	int		bpp;
	int		endian;

	bpp = 32;
	endian = 1;
	new = (t_win *)malloc(sizeof(t_win));
	if (!new)
		return (NULL);
	new->width = width;
	new->height = height;
	new->mlx = mlx_ptr;
	new->win = win_ptr;
	new->img = mlx_new_image(mlx_ptr, width, height);
	if (!new->img)
	{
		free(new);
		return (NULL);
	}
	new->data = (int *)mlx_get_data_addr(new->img, &bpp, &trsh, &endian);
	return (new);
}
