/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:19:05 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/30 08:52:45 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipexu(int inputf, int outputf, char **arg, char **env)
{
	pid_t child1;
	pid_t child2;
	int	end[2];
	int status;
	
	pipe(end);
	child1 = fork();
	if(child1 < 0)
		return(perror("fork"));
	if (!child1)
		cmd1(inputf, find_cmd(arg[2], env), end);		
	child2 = fork();
	if(child2 < 0)
		return(perror("fork"));
	if (!child2)
		cmd2(outputf, find_cmd(arg[3], env), end);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	cmd1(int infile, char **cmd1, int *fd)
{
	int		res;

	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	res = execve(cmd1[0], cmd1, NULL);
	if (res == -1)
		perror("execve");
	return(EXIT_FAILURE);
}

int	cmd2(int outfile, char **cmd2, int *fd)
{
	int	res;
	
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(outfile);
	res = execve(cmd2[0], cmd2, NULL);
	if (res == -1)
		perror("execve");
	return(EXIT_FAILURE);
}

int	file_input_check(char *file)
{
	if(access(file, F_OK) == 0)
		return (1);
	else
		return (0);
}
