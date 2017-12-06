/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 09:08:59 by ecloete           #+#    #+#             */
/*   Updated: 2017/09/25 10:17:00 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				key_hook(int keycode, t_proc *a)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		a->indx -= 20;
	if (keycode == 124)
		a->indx += 20;
	if (keycode == 126)
		a->indy -= 20;
	if (keycode == 125)
		a->indy += 20;
	if (keycode == 69)
		a->zoom += 3;
	if (keycode == 78)
		a->zoom = ft_clamp(0, a->zoom, a->zoom - 1);
	mlx_clear_window(a->mlx, a->win);
	printchar(a);
	return (1);
}

int				rv(int x, int y, int s, int deg)
{
	int			v;

	if (s == 1)
	{
		if (deg != 0)
			v = x * cos(DEG_T_RAD * deg) - y * sin(DEG_T_RAD * deg);
		else
			v = (x - y);
	}
	else
	{
		if (deg != 0)
			v = x * sin(DEG_T_RAD * deg) + y * cos(DEG_T_RAD * deg);
		else
			v = round((x + y) / 2);
	}
	return (v);
}

int				printchar(t_proc *a)
{
	int			n;

	mlx_string_put(a->mlx, a->win, AX / 3, AY / 2, WHITE, "FDF");
	AY = 0;
	AX = 0;
	while (AY < a->size_y)
	{
		while (AX < a->size_x)
		{
			a->i = rv((AX * AZ * 2), (AY * AZ * 2), -1, DEG);
			a->i += a->indy - (AMX * a->zoom / 5);
			if (a->i > 1000)
				a->i = 0;
			if ((n = ((rv((AX * AZ), (AY * AZ * 2), 1, DEG)) + a->indx)) > 1000)
				n = 0;
			ASX = n * 1000 + a->i;
			AX++;
		}
		AX = 0;
		AY++;
	}
	printchar_p2(a);
	return (1);
}

int				fillarry(t_proc *a)
{
	char	**strsplt;
	int		i;

	AX = 0;
	AY = 0;
	i = 0;
	while (get_next_line(a->fd, &a->line) == 1)
	{
		strsplt = ft_strsplit(a->line, ' ');
		while (strsplt[i])
		{
			AMX = ft_atoi(strsplt[i]);
			AX++;
			free(strsplt[i]);
			i++;
		}
		free(strsplt);
		free(a->line);
		i = 0;
		AY++;
		AX = 0;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_proc		a;

	if (ac != 2)
	{
		ft_putstr("Please specify file.\n");
		return (0);
	}
	if (!ft_strstr(av[1], ".fdf"))
	{
		ft_putstr("Only *.fdf files can be used.\n");
		return (0);
	}
	if ((a.fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("Can't open file.\n");
		return (0);
	}
	a.file_name = av[1];
	prep_var(&a, av[1]);
	fillarry(&a);
	printchar(&a);
	mlx_key_hook(a.win, key_hook, &a);
	mlx_loop(a.mlx);
	return (0);
}
