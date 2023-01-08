/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 02:39:54 by machaiba          #+#    #+#             */
/*   Updated: 2023/01/07 22:56:24 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef struct pipex
{
	int		fd[2];
	int		id;
	int		id2;
	int		x;
	int		infile;
	int		outfile;
}	t_all;

typedef struct pipex2
{
	int		x;
	int		y;
	char	**str;
	char	**str1;
	char	*join1;
	char	*join2;
}	t_cmd;

char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**get_path(char **env);
char	*cmdcheck(char **av, char **env);
char	*cmdcheck2(char **av, char **env);
void	child1(char **av, char **env);

#endif