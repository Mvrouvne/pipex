/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:26:11 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/11 16:25:26 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmdcheck2(char **av, char **env)
{
	t_cmd	pi;

	pi.str = get_path(env);
	pi.str1 = ft_split(av[3], ' ');
	pi.x = 0;
	if (av[3][0] == '/')
	{
		execve(av[3], pi.str1, env);
		write(2, "command not found\n", 18);
		exit(127);
	}
	while (pi.str && pi.str[pi.x])
	{
		pi.join1 = ft_strjoin(pi.str[pi.x], "/");
		pi.join2 = ft_strjoin(pi.join1, pi.str1[0]);
		if (access(pi.join2, X_OK) == 0)
			execve(pi.join2, pi.str1, env);
		free(pi.join1);
		free(pi.join2);
		pi.x++;
	}
	write(2, "command not found\n", 18);
	exit(127);
}
