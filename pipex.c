/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:26:05 by nfoughal          #+#    #+#             */
/*   Updated: 2022/12/19 17:15:00 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ch_process(char **argv, char **env, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error();
	if (dup2(infile, STDIN_FILENO) == -1)
		error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error();
	close(fd[0]);
	get_execve(argv[2], env);
}

void	pr_process(char **argv, char **env, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error();
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error();
	close(fd[1]);
	get_execve(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			ch_process(argv, env, fd);
		pr_process(argv, env, fd);
	}
	ft_putstr_fd("Error: Wrong argument number", 2);
	return (0);
}
