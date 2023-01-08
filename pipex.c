/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:01:57 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/08 22:39:02 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork1(char **av, char **env, t_all pi)
{
	if (pi.id == -1)
	{
		perror ("Fork Error 1");
		exit(1);
	}
	if (pi.id == 0)
	{
		close (pi.fd[0]);
		dup2(pi.infile, 0);
		dup2(pi.fd[1], 1);
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

void	ft_justnorm(char **av, char **env, t_all pi)
{
	if (pipe(pi.fd) == -1)
	{
		perror("Pipe Error");
		exit(1);
	}
	pi.id = fork();
	fork1(av, env, pi);
	pi.id2 = fork();
	if (pi.id2 == -1)
	{
		perror("Fork Error 2");
		exit(1);
	}
	if (pi.id2 == 0)
	{
		close(pi.fd[1]);
		dup2(pi.fd[0], 0);
		dup2(pi.outfile, 1);
		cmdcheck2(av, env);
	}
	parent(pi);
}

int	main(int ac, char **av, char **env)
{
	t_all	pi;

	pi.x = 0 ;
	pi.infile = open(av[1], O_RDWR);
	if (pi.infile == -1)
	{
		write(2, "no such file or directory\n", 27);
		exit(1);
	}
	pi.outfile = open("outfile", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pi.outfile == -1)
	{
		write(2, "no file is created\n", 20);
		exit(1);
	}
	if (ac == 5)
	{
		ft_justnorm(av, env, pi);
	}
	else
	{
		write(2, "Less than 4 arguments!!\n", 25);
		exit(1);
	}
}
