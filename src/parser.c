/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:33:54 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/19 21:12:50 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains functiosn related to the parsing of the map.
**
** count_numbers : counts how many numbers there is in the map. If the function
** detects any character that isn't part of a number or a space
** it returns an error, indicated by a -1.
**
** parser : uses a get_next_line function to read the file. It counts for each
** line how many numbers there is via count_numbers, and if the number of
** numbers between the first line and another is not equal, it returns an
** error.
** It also saves the number of numbers for a line and the number of lines.
*/

#include "fdf.h"

int		count_numbers(char *s)
{
	int		i;
	int		nbs;

	i = 0;
	nbs = 0;
	while (s[i])
	{
		while (s[i] == ' ' && s[i])
			i++;
		if (!s[i])
			return (nbs);
		nbs++;
		i = ((s[i] == '-' || s[i] == '+')
				&& s[i + 1] <= '9' && s[i + 1] >= '0') ? i + 1 : i;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (s[i] != ' ' && s[i] != '\0')
			return (-1);
	}
	return (nbs);
}

t_env	*parser(t_env *var)
{
	int		ret;
	char	*line;

	line = ft_strnew(0);
	var->nb = 0;
	var->lines = 0;
	while ((ret = get_next_line(var->fd, &line)))
	{
		if (ret == -1)
			error_handle("Can't read the file.");
		if (var->nb == 0)
			var->nb = count_numbers(line);
		else if (count_numbers(line) != var->nb || var->nb == -1)
			error_handle("Invalid file.");
		var->lines++;
	}
	ft_strdel(&line);
	close(var->fd);
	return (var);
}
