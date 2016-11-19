/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:38:42 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 20:56:30 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	commands_disp(t_env *v)
{
	mlx_string_put(v->mlx, v->win, 0, 0, 0xEFEFEF, "Esc     = Quit");
	mlx_string_put(v->mlx, v->win, 0, 15, 0xEFEFEF, "Arrows  = Move");
	mlx_string_put(v->mlx, v->win, 0, 30, 0xEFEFEF, "C       = Reset");
	mlx_string_put(v->mlx, v->win, 0, 45, 0xEFEFEF, "+ / -   = Zoom");
	mlx_string_put(v->mlx, v->win, 0, 60, 0xEFEFEF, "Map : ");
	mlx_string_put(v->mlx, v->win, 56, 60, 0xEFEFEF, v->name);
}

static int	refresher(t_env *v)
{
	mlx_clear_window(v->mlx, v->win);
	draw(v);
	commands_disp(v);
	return (0);
}

static int	on_keydown(int keycode, t_env *v)
{
	ft_putstr("Your keycode is ");
	ft_putnbr(keycode);
	ft_putendl(" !");
	v->s_line = v->s_line;
	if (keycode == 8)
		remake(v);
	if (keycode == 53)
		exit(1);
	else if (keycode == 123)
		translate(v, -8, 0);
	else if (keycode == 124)
		translate(v, 8, 0);
	else if (keycode == 125)
		translate(v, 0, 8);
	else if (keycode == 126)
		translate(v, 0, -8);
	else if (keycode == 78)
		zoom(v, 1);
	else if (keycode == 69)
		zoom(v, -1);
	refresher(v);
	return (0);
}

void		mlx_calls(t_env *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIN_X, WIN_Y, "FdF");
	draw(v);
	commands_disp(v);
	mlx_hook(v->win, 2, 2, on_keydown, v);
	mlx_expose_hook(v->win, refresher, v);
	mlx_loop(v->mlx);
}
