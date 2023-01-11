/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:01:57 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/11 16:41:23 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork1(char **av, char **env, t_all pi)
{
	if (pi.id == -1)
	{
		write(2, "Fork 1 Error\n", 14);
		exit(1);
	}
	if (pi.id == 0)
	{
		close (pi.fd[0]);
		if (dup2(pi.infile, 0) == -1)
		{
			write (2, "Dup2 Error\n", 12);
			exit(1);
		}
		if (dup2(pi.fd[1], 1) == -1)
		{
			write (2, "Dup2 Error\n", 12);
			exit(1);
		}
		cmdcheck(av, env);
	}
}

void	parent(t_all	pi)
{
	close(pi.fd[0]);
	close(pi.fd[1]);
	close(pi.infile);
	close(pi.outfile);
	waitpid(pi.id, NULL, 0);
	waitpid(pi.id2, NULL, 0);
}

void	fork2(char **av, char **env, t_all pi)
{
	if (pi.id2 == -1)
	{
		write(2, "Fork 2 Error\n", 14);
		exit(1);
	}
	if (pi.id2 == 0)
	{
		close(pi.fd[1]);
		if (dup2(pi.fd[0], 0) == -1)
		{
			write (2, "Dup2 Error\n", 12);
			exit(1);
		}
		if (dup2(pi.outfile, 1) == -1)
		{
			write (2, "Dup2 Error\n", 12);
			exit(1);
		}
		cmdcheck2(av, env);
	}
}

void	ft_justnorm(char **av, char **env, t_all pi)
{
	if (pipe(pi.fd) == -1)
	{
		write(2, "Pipe Error\n", 12);
		exit(1);
	}
	pi.id = fork();
	fork1(av, env, pi);
	pi.id2 = fork();
	fork2(av, env, pi);
	parent(pi);
}

int	main(int ac, char **av, char **env)
{
	t_all	pi;

	pi.x = 0 ;
	if (ac == 5)
	{
		pi.infile = open(av[1], O_RDWR);
		if (pi.infile == -1)
		{
			write(2, "no such file or directory\n", 27);
			exit(1);
		}
		pi.outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (pi.outfile == -1)
		{
			write(2, "no file is created\n", 20);
			exit(1);
		}
		ft_justnorm(av, env, pi);
	}
	else
	{
		write(1, "4 arguments required!!!\n", 25);
		exit(1);
	}
}
