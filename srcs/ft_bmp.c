/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:31:19 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:31:22 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bmp	init_bmp(t_all *all)
{
	t_bmp	bmp;

	bmp.massiv = (char *)malloc(sizeof(char) * 3);
	bmp.massiv[0] = 'B';
	bmp.massiv[1] = 'M';
	bmp.massiv[2] = '\0';
	bmp.app_spe = 0;
	bmp.data_offset = 54;
	bmp.size_dib = 40;
	bmp.width = all->width;
	bmp.heigth = all->heigth;
	bmp.planes = 1;
	bmp.bpp = 32;
	bmp.size_file = bmp.data_offset + ((bmp.width * bmp.heigth) * 4);
	bmp.data_ptr = all->img->data;
	bmp.trash = 0;
	return (bmp);
}

void	write_file(int fd, t_bmp bmp)
{
	int	x;
	int	y;
	int	mix_bpp;

	y = bmp.heigth - 1;
	mix_bpp = bmp.bpp;
	mix_bpp = (mix_bpp << 16) + bmp.planes;
	ft_putstr_fd(bmp.massiv, fd);
	write(fd, &bmp.size_file, 4);
	write(fd, &bmp.app_spe, 4);
	write(fd, &bmp.data_offset, 4);
	write(fd, &bmp.size_dib, 4);
	write(fd, &bmp.width, 4);
	write(fd, &bmp.heigth, 4);
	write(fd, &mix_bpp, 4);
	write(fd, &bmp.trash, 8);
	write(fd, &bmp.trash, 8);
	write(fd, &bmp.trash, 8);
	while (y >= 0)
	{
		x = 0;
		while (x < bmp.width)
			write(fd, &(bmp.data_ptr[(y * bmp.width) + x++]), 4);
		y--;
	}
}

void	ft_bmp(t_all *all)
{
	int		fd;
	t_bmp	bmp;

	fd = open("something.bmp", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
	{
		free(all);
		ft_errors(11);
	}
	all->img = my_mlx_new_image(all->mlx, all->win, all->width, all->heigth);
	if (!all->img)
	{
		free(all);
		ft_errors(11);
	}
	movings_player(all);
	draw_background(all);
	perform_raycasting(all);
	draw_sprites(all);
	bmp = init_bmp(all);
	write_file(fd, bmp);
	close(fd);
	free(all);
	exit(0);
}
