/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:55:36 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 21:06:35 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**clean_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = ft_strnew(0);
	}
	return (tab);
}

t_coor		**get_tab(t_coor **p, char **tab, int i, int nb)
{
	int		j;

	j = 0;
	p[i] = (t_coor *)malloc(sizeof(t_coor) * nb);
	while (j < nb)
	{
		p[i][j].x = j;
		p[i][j].y = i;
		p[i][j].z = ft_atoi(tab[j]);
		j++;
	}
	return (p);
}

t_coor		**save_map(t_env *v)
{
	t_coor	**p;
	char	*line;
	char	**tab;
	int		ret;
	int		i;

	i = 0;
	line = ft_strnew(0);
	p = (t_coor **)malloc(sizeof(t_coor *) * v->lines);
	while ((ret = get_next_line(v->fd, &line)))
	{
		tab = ft_strsplit(line, ' ');
		p = get_tab(p, tab, i++, v->nb);
		tab = clean_tab(tab);
	}
	ft_strdel(&line);
	close(v->fd);
	return (p);
}
