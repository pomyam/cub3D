/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:43:36 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/27 13:11:06 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*putsave(char *save);
char	*putline(char *str);
int		ifn(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
#endif
