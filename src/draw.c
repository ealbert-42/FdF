/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:30:56 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 20:23:48 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_pixel_put(unsigned char *px, int x, int y, t_env *v)
{
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		px[y * v->s_line + x * v->bpp / 8] =
			(unsigned char)v->color % 256;
		px[(y * v->s_line + x * v->bpp / 8) + 1] =
			(unsigned char)(v->color >> 8) % 256;
		px[(y * v->s_line + x * v->bpp / 8) + 2] =
			(unsigned char)(v->color >> 16) % 256;
	}
}

static void	drawing(t_pts **pts, t_env *v)
{
	int				i;
	int				j;
	unsigned char	*px;

	px = v->data;
	i = 0;
	while (i < v->lines)
	{
		j = 0;
		while (j < v->nb)
		{
			v->color = (v->p[i][j].z == 0) ? C_RED : C_GREEN;
			ft_pixel_put(px, (unsigned int)pts[i][j].x, \
					(unsigned int)pts[i][j].y, v);
			j++;
		}
		i++;
	}
	draw_line1(pts, v);
}

void		draw(t_env *v)
{
	v->img = mlx_new_image(v->mlx, WIN_X, WIN_Y);
	v->data = (unsigned char *)mlx_get_data_addr(v->img, &(v->bpp),
			&(v->s_line), &(v->end));
	drawing(v->pts, v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
