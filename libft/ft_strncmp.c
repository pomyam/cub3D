/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:10:44 by pyamcha           #+#    #+#             */
/*   Updated: 2020/11/22 17:48:56 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s1);
	if (!(ft_memcmp(s1, s2, n)))
		return (0);
	if (n < len)
		return (ft_memcmp(s1, s2, n));
	else
		return (ft_memcmp(s1, s2, len + 1));
}
