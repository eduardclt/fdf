/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:10:28 by ecloete           #+#    #+#             */
/*   Updated: 2017/09/25 09:42:26 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# define GREEN	0x0000FF00
# define RED	0x00FF0000
# define BLUE	0x000000FF
# define WHITE	0x00FFFFFF
# define AM a->m
# define AS a->s
# define AX a->x
# define AY a->y
# define AI a->i
# define AZ a->zoom
# define AMX AM[AY][AX]
# define ASX AS[AY][AX]
# define DEG_T_RAD	2 * M_PI / 180
# define DEG 0

typedef struct	s_proc {

	char		*file_name;
	void		*mlx;
	void		*win;
	void		*img;
	int			size_x;
	int			size_y;
	int			x;
	int			y;
	int			**m;
	int			s[1000][1000];
	int			fd;
	int			i;
	char		*line;
	int			color[1000];
	int			indx;
	int			indy;
	int			zoom;
	int			rot;
}				t_proc;

typedef struct	s_draw {
	int			dx;
	int			dy;
	int			steps;
	float		xinc;
	float		yinc;
	float		x;
	float		y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			i;
}				t_draw;

void			prep_var(t_proc *a, char *av);
int				isdir(t_proc *a);
int				put_pixel(t_proc *a, int x, int y);
int				printchar(t_proc *a);
int				draw_line(t_proc *a, t_draw *d);
int				printchar_p2(t_proc *a);
int				put_pixel(t_proc *a, int x, int y);

#endif
