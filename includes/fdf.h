/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:01:59 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 21:56:06 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Defines for FdF
*/

# define WIN_Y 900
# define WIN_X 1600
# define C_RED 0xFF0000
# define C_GREEN 0xFF00

/*
** Includes
*/

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

/*
** Helpful structures
*/

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				i;
	int				e;
	int				x;
	int				y;
	int				xinc;
	int				yinc;
	int				inc1;
	int				inc2;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}					t_line;

typedef struct		s_pts
{
	double			x;
	double			y;
}					t_pts;

typedef struct		s_coor
{
	int				x;
	int				y;
	int				z;
}					t_coor;

typedef struct		s_env
{
	void			*mlx;
	void			*img;
	void			*win;
	unsigned char	*data;
	int				bpp;
	int				zoom;
	int				end;
	int				s_line;
	int				xtr;
	int				ytr;
	t_coor			**p;
	t_pts			**pts;
	t_line			l;
	int				fd;
	char			*name;
	char			*line;
	int				nb;
	int				lines;
	unsigned int	color;
}					t_env;

/*
** main.c
*/

void				error_handle(char *s);

/*
** save.c
*/

t_coor				**save_map(t_env *var);

/*
** parser.c
*/

t_env				*parser(t_env *var);

/*
** matrix.c
*/

t_pts				**save_points(t_env *v);

/*
** hooks.c
*/

void				mlx_calls(t_env *v);

/*
** draw.c
*/

void				draw(t_env *v);
void				ft_pixel_put(unsigned char *px, int x, int y, t_env *v);

/*
** draw_img.c
*/

void				draw_line1(t_pts **pts, t_env *v);

/*
** change.c
*/

void				translate(t_env *v, int x, int y);
void				remake(t_env *v);
void				zoom(t_env *v, int i);

#endif
