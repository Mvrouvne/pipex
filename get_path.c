/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:20:09 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/07 15:53:14 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	int		x;
	char	*str;
	char	**envi;

	x = 0;
	envi = NULL;
	while (env[x])
	{
		if (env[x][0] == 'P' && env[x][1] == 'A' && env[x][2] == 'T'
			&& env[x][3] == 'H' && env[x][4] == '=')
		{
			str = ft_substr(env[x], 5, ft_strlen(env[x]));
			envi = ft_split(str, ':');
			free (str);
		}
		x++;
	}
	return (envi);
}
