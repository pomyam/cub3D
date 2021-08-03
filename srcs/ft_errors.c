/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:31:48 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:31:50 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	other_errors(int fd)
{
	if (fd == 12)
		printf("Error\nwindow can be created!\n");
	else if (fd == 13)
		printf("Error\nyour image are not correct");
	else if (fd == 14)
		printf("Error\nmemory allocation error encountered.\n");
	else if (fd == 15)
		printf("Error\nimage can't be created.\n");
	exit(1);
}

void	ft_errors(int fd)
{
	if (fd == 1)
		printf("Error\nI can't open file\n");
	else if (fd == 2)
		printf("Error\nmalloc can't be here!\n");
	else if (fd == 3)
		printf("Error\nyou give incorrect number of arguments\n");
	else if (fd == 4)
		printf("Error\nyou make incorrect file format\n");
	else if (fd == 5)
		printf("Error\nyou make incorrect second argument\n");
	else if (fd == 6)
		printf("Error\nI can't make map!\n");
	else if (fd == 7)
		printf("Error\nmalloc can't be here!\n");
	else if (fd == 8)
		printf("Error\nyou make invalid file content\n");
	else if (fd == 9)
		printf("Error\nfile incorrect!\n");
	else if (fd == 11)
		printf("Error\ncan't make photo!\n");
	else
		other_errors(fd);
	exit(1);
}
