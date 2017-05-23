/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:08:57 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 19:34:04 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_line4(unsigned char *px, t_line l, t_env *v)
{
	l.i = 1;
	l.e = 2 * l.dx - l.dy;
	l.inc1 = 2 * (l.dx - l.dy);
	l.inc2 = 2 * l.dx;
	while (l.i < l.dy)
	{
		if (l.e >= 0)
		{
			l.x += l.xinc;
			l.e += l.inc1;
		}
		else
			l.e += l.inc2;
		l.y += l.yinc;
		ft_pixel_put(px, l.x, l.y, v);
		l.i++;
	}
}

void			draw_line3(unsigned char *px, t_line l, t_env *v)
{
	l.i = 1;
	l.e = 2 * l.dy - l.dx;
	l.inc1 = 2 * (l.dy - l.dx);
	l.inc2 = 2 * l.dy;
	while (l.i < l.dx)
	{
		if (l.e >= 0)
		{
			l.y += l.yinc;
			l.e += l.inc1;
		}
		else
			l.e += l.inc2;
		l.x += l.xinc;
		ft_pixel_put(px, l.x, l.y, v);
		l.i++;
	}
}

static t_line	init_line(t_line l, t_pts **pts, int i, int j)
{
	l.x1 = pts[i][j].x;
	l.y1 = pts[i][j].y;
	l.x2 = (l.i == 1) ? pts[i][j + 1].x : pts[i + 1][j].x;
	l.y2 = (l.i == 1) ? pts[i][j + 1].y : pts[i + 1][j].y;
	l.dx = abs(l.x2 - l.x1);
	l.dy = abs(l.y2 - l.y1);
	l.xinc = (l.x2 < l.x1) ? -1 : 1;
	l.yinc = (l.y2 < l.y1) ? -1 : 1;
	l.x = l.x1;
	l.y = l.y1;
	return (l);
}

void			draw_line2(t_pts **pts, t_env *v)
{
	int				i;
	int				j;
	unsigned char	*px;

	px = v->data;
	j = -1;
	while (++j < v->nb)
	{
		i = -1;
		while (++i < v->lines - 1)
		{
			v->color = (!v->p[i][j].z && !v->p[i + 1][j].z) ? C_RED : C_GREEN;
			v->l.i = 2;
			v->l = init_line(v->l, pts, i, j);
			if (v->l.dx > v->l.dy)
				draw_line3(px, v->l, v);
			else
				draw_line4(px, v->l, v);
		}
	}
}

void			draw_line1(t_pts **pts, t_env *v)
{
	int				i;
	int				j;
	unsigned char	*px;

	px = v->data;
	i = -1;
	while (++i < v->lines)
	{
		j = -1;
		while (++j < v->nb - 1)
		{
			v->color = (!v->p[i][j].z && !v->p[i][j + 1].z) ? C_RED : C_GREEN;
			v->l.i = 1;
			v->l = init_line(v->l, pts, i, j);
			if (v->l.dx > v->l.dy)
				draw_line3(px, v->l, v);
			else
				draw_line4(px, v->l, v);
		}
	}
	draw_line2(pts, v);
}
