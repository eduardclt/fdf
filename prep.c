/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 09:11:19 by ecloete           #+#    #+#             */
/*   Updated: 2017/09/25 10:16:42 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		map_alloc(t_proc *a)
{
	char	*line;
	char	**split;
	int		y_fd;
	int		x_fd;
	int		y;

	y_fd = open(a->file_name, O_RDONLY);
	x_fd = open(a->file_name, O_RDONLY);
	while (get_next_line(y_fd, &line) == 1)
	{
		a->size_y++;
		free(line);
	}
	a->m = (int **)malloc(sizeof(int *) * a->size_y);
	get_next_line(x_fd, &line);
	split = ft_strnsplit(line, ' ', &(a->size_x));
	while (*split)
		free(*split++);
	free(line);
	y = a->size_y;
	while (--y >= 0)
		(a->m[y] = (int *)malloc(sizeof(int) * a->size_x));
	close(y_fd);
	close(x_fd);
}

void		prep_var(t_proc *a, char *av)
{
	map_alloc(a);
	a->zoom = 14;
	if (a->size_x > 150 || a->size_y > 150)
		a->zoom = 3;
	a->x = 0;
	a->y = 0;
	a->rot = 45;
	a->indx = 300;
	a->indy = 100;
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, 800, 800, av);
}
