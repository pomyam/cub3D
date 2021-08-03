/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:35:02 by pyamcha           #+#    #+#             */
/*   Updated: 2021/05/06 14:35:03 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_list(t_param *list)
{
	free(list->no);
	free(list->so);
	free(list->ea);
	free(list->we);
	free(list->s);
	exit(0);
}

void	ft_del(void *content)
{
	(void)content;
}

void	ft_make_map(t_list **head, t_param *list, int len)
{
	t_list	*n;
	int		length;
	char	**map;
	int		i;

	i = 0;
	n = *head;
	length = ft_lstsize(*head);
	map = malloc(sizeof(char *) * (length + 1));
	if (!map)
		ft_errors(6);
	while (n)
	{
		map[i++] = n->content;
		n = n->next;
	}
	map[i] = NULL;
	n = (*head)->next;
	ft_lstclear(head, *ft_del);
	ft_parser(map, list, len);
	free((void *)map);
}

void	ft_check_av(int ac, char **av, t_param *list)
{
	int		length;

	length = ft_strlen(av[1]);
	if (ac < 2 || ac > 3)
		ft_errors(3);
	if (av[1][length - 1] != 'b' || av[1][length - 2] != 'u'
		|| av[1][length - 3] != 'c' || av[1][length - 4] != '.')
		ft_errors(4);
	if (ac != 3)
		return ;
	if (ft_strncmp(av[2], "--save", 10) != 0)
		ft_errors(5);
	else
		list->save = 1;
}

int	main(int ac, char **av)
{
	int		fd;
	int		readed;
	char	*line;
	t_list	*head;
	t_param	*list;

	init_list(&list);
	readed = 1;
	line = NULL;
	ft_check_av(ac, av, list);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_errors(1);
	while (readed)
	{
		readed = get_next_line(fd, &line);
		ft_lstadd_back(&head, ft_lstnew(line));
		if (list->max < (int)ft_strlen(line))
			list->max = (int)ft_strlen(line);
		list->length++;
	}
	ft_lstadd_back(&head, ft_lstnew(list));
	close(fd);
	ft_make_map(&head, list, list->length);
	return (0);
}
