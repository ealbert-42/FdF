/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:54:42 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 21:57:01 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pts		**save_points(t_env *v)
{
	t_pts	**pts;
	int		i;
	int		j;

	i = 0;
	pts = (t_pts **)malloc(sizeof(t_pts *) * v->lines);
	while (i < v->lines)
	{
		j = 0;
		pts[i] = (t_pts *)malloc(sizeof(t_pts) * v->nb);
		while (j < v->nb)
		{
			pts[i][j].x = v->xtr + (WIN_X / 2)
				+ v->p[i][j].x * v->zoom - i * v->zoom;
			pts[i][j].y = v->ytr + (WIN_Y / 4) + v->p[i][j].y * v->zoom \
				- v->p[i][j].z * v->zoom / 7;
			j++;
		}
		i++;
	}
	return (pts);
}
