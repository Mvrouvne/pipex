/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:01:57 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/06 22:35:24 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	t_all	pi;
	

	pi.x = 0 ;
	pi.infile = open(av[1], O_RDWR);
	if (pi.infile == -1)
	{
		write(2, "no such file or directory", 25);
		exit(1);
	}
	pi.outfile = open("outfile", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pi.outfile == -1)
	{
		write(2, "no file is created", 18);
		exit(1);
	}

	
	if (ac == 5)
	{
		if (pipe(pi.fd) == -1)
		{
			perror("Pipe Error");
			exit(1);
		}
		pi.id = fork();
		if (pi.id == -1)
		{
			perror ("Fork Error 1");
			exit(1);
		}
		if (pi.id == 0)
		{
			//child 1
			close (pi.fd[0]);
			dup2(pi.infile, 0);
			dup2(pi.fd[1], 1);
			cmdcheck(av, env);
		}

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

		else
		{
			//parent process
			close(pi.fd[0]);
			close(pi.fd[1]);
			close(pi.infile);
			close(pi.outfile);
		}
	}
	else
	{
		printf("Less than 5 parameters!!");
		exit(1);
	}
}