/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:33:45 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/11 15:49:49 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmdcheck(char **av, char **env)
{
	t_cmd	pi;

	pi.str = get_path(env);
	pi.str1 = ft_split(av[2], ' ');
	pi.x = 0;
	if (av[2][0] == '/')
	{
		execve(av[2], pi.str1, env);
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
