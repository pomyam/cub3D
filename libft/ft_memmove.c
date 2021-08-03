/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:59:37 by pyamcha           #+#    #+#             */
/*   Updated: 2020/11/22 18:27:43 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (str1 > str2)
	{
		i = n;
		while (i-- > 0)
			str1[i] = str2[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			str1[i] = str2[i];
	}
	return (dest);
}
