/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:34:55 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/07 15:49:15 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s1)
{
	char	*p;
	int		len;
	int		x;

	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		p[x] = s1[x];
		x++;
	}
	p[x] = '\0';
	return (p);
}
