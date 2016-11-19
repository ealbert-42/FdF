/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel.                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 17:12:09 by ealbert           #+#    #+#             */
/*   Updated: 2016/03/13 17:56:49 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdel(char *str, int c)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] != c)
		i++;
	j = ft_strlen(str) - i;
	if (!(new = (char *)malloc(sizeof(char) * j)))
		return (NULL);
	j = 0;
	while (str[++i] != '\0')
		new[j++] = str[i];
	new[j] = '\0';
	free(str);
	return (new);
}
