/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:26:11 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/06 22:32:58 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *cmdcheck2(char **av, char **env)
{
	int     x;
	int     y;
	char    **str = get_path(env);
	char    **str1 = ft_split(av[3], ' ');
	char	*join1;
	char	*join2;
	
	x = 0;
	y = 0;
	if (av[3][0] == '/')
	{
		execve(av[3], str1, env);
		write(2, "command not found\n", 19);
		exit(127);
	}
	
	while (str && str[y])
	{
		join1 = ft_strjoin(str[y] , "/");
		join2 = ft_strjoin(join1 , str1[0]);
		if (access(join2, X_OK) == 0)
			execve(join2, str1, env);
		free(join1);
		free(join2);
		y++;
	}
	write(2, "command not found\n", 19);
	exit(127);
}

// int	main(int ac, char **av,  char **env)
// {
// 	printf("%s", cmdcheck(av, env));
// }