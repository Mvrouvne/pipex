/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:39:45 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/07 21:29:51 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!join)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x])
	{
		join[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		join[x] = s2[y];
		y++;
		x++;
	}
	join[x] = '\0';
	return (join);
}
