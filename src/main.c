/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:22:50 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 21:06:02 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			error_handle(char *s)
{
	ft_putendl(s);
	exit(0);
}

static char		*trim_slash(char *s)
{
	int		i;
	int		keep;

	i = -1;
	keep = 0;
	while (s[++i])
	{
		if (s[i] == '/')
			keep = i + 1;
	}
	if (keep == 0)
		return (s);
	return (ft_strsub(s, keep, i - keep));
}

static t_env	*var_init(t_env *v)
{
	v->end = 1;
	v->s_line = WIN_X;
	v->bpp = 8;
	v->zoom = 10;
	return (v);
}

int				main(int ac, char **av)
{
	t_env *v;

	if (ac != 2)
		error_handle("Usage : ./fdf \"MAPFILE\"");
	v = (t_env *)malloc(sizeof(t_env));
	v = var_init(v);
	v->name = ft_strdup(trim_slash(av[1]));
	if ((v->fd = open(av[1], O_RDONLY)) == -1)
		error_handle("Error while opening the file.");
	v = parser(v);
	v->fd = open(av[1], O_RDONLY);
	v->p = save_map(v);
	v->pts = save_points(v);
	mlx_calls(v);
	return (0);
}
