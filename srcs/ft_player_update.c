/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:33:35 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:33:36 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	finder(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	back(t_all *s)
{
	double	temp;

	if (s->key_back)
	{
		temp = s->posx - (s->dirx * s->mspeed);
		if (finder("1", s->map[(int)(s->posy)][(int)(temp)]) == 0)
			s->posx = temp;
		temp = s->posy - (s->diry * s->mspeed);
		if (finder("1", s->map[(int)(temp)][(int)(s->posx)]) == 0)
			s->posy = temp;
	}
}

void	rotation(t_all *s)
{
	double	olddirx;
	double	oldplanx;

	olddirx = s->dirx;
	oldplanx = s->planx;
	if (s->key_rr)
	{
		s->dirx = s->dirx * cos(-s->rspeed) - s->diry * sin(-s->rspeed);
		s->diry = olddirx * sin(-s->rspeed) + s->diry * cos(-s->rspeed);
		s->planx = s->planx * cos(-s->rspeed) - s->plany * sin(-s->rspeed);
		s->plany = oldplanx * sin(-s->rspeed) + s->plany * cos(-s->rspeed);
	}
	if (s->key_rl)
	{
		s->dirx = s->dirx * cos(s->rspeed) - s->diry * sin(s->rspeed);
		s->diry = olddirx * sin(s->rspeed) + s->diry * cos(s->rspeed);
		s->planx = s->planx * cos(s->rspeed) - s->plany * sin(s->rspeed);
		s->plany = oldplanx * sin(s->rspeed) + s->plany * cos(s->rspeed);
	}
}

void	movement(t_all *s)
{
	double	temp;

	if (s->key_rigth)
	{
		temp = s->posx + (s->planx * s->mspeed);
		if (finder("1", s->map[(int)(s->posy)][(int)(temp)]) == 0)
			s->posx += s->planx * s->mspeed;
		temp = s->posy + (s->plany * s->mspeed);
		if (finder("1", s->map[(int)(temp)][(int)(s->posx)]) == 0)
			s->posy += s->plany * s->mspeed;
	}
	if (s->key_left)
	{
		temp = s->posx - (s->planx * s->mspeed);
		if (finder("1", s->map[(int)(s->posy)][(int)(temp)]) == 0)
			s->posx -= s->planx * s->mspeed;
		temp = s->posy - (s->plany * s->mspeed);
		if (finder("1", s->map[(int)(temp)][(int)(s->posx)]) == 0)
			s->posy -= s->plany * s->mspeed;
	}
}

void	movings_player(t_all *all)
{
	double	temp;

	if (all->key_w == -1 || all->key_back == -1 || all->key_left == -1
		|| all->key_rigth == -1 || all->key_rl == -1 || all->key_rr == -1)
	{
		all->key_w = 0;
		all->key_back = 0;
		all->key_left = 0;
		all->key_rigth = 0;
		all->key_rr = 0;
		all->key_rl = 0;
	}
	if (all->key_w)
	{
		temp = all->posx + (all->dirx * all->mspeed);
		if (finder("1", all->map[(int)(all->posy)][(int)(temp)]) == 0)
			all->posx += all->dirx * all->mspeed;
		temp = all->posy + (all->diry * all->mspeed);
		if (finder("1", all->map[(int)(temp)][(int)(all->posx)]) == 0)
			all->posy += all->diry * all->mspeed;
	}
	rotation(all);
	movement(all);
	back(all);
}
