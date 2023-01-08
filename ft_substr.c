/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:33:09 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/07 15:50:34 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char			*subs;
	size_t			x;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len + start > ft_strlen(str))
		len = ft_strlen(str) - start;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	x = 0;
	while (x < len)
	{
		subs[x] = str[start];
		x++;
		start++;
	}
	subs[x] = '\0';
	return (subs);
}
