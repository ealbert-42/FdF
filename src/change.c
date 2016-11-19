/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:46:46 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 20:53:21 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		remake(t_env *v)
{
	int		i;

	i = -1;
	v->zoom = 10;
	while (++i < v->lines)
		free(v->pts[i]);
	v->pts = NULL;
	v->pts = save_points(v);
}

static void	z_remake(t_env *v)
{
	int		i;

	i = -1;
	while (++i < v->lines)
		free(v->pts[i]);
	v->pts = NULL;
	v->pts = save_points(v);
}

void		zoom(t_env *v, int i)
{
	if (i == 1 && v->zoom != -1)
		v->zoom++;
	else if (i == -1 && v->zoom != 1)
		v->zoom--;
	z_remake(v);
}

void		translate(t_env *v, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < v->lines)
	{
		j = -1;
		while (++j < v->nb)
		{
			v->pts[i][j].x += x;
			v->pts[i][j].y += y;
		}
	}
}
