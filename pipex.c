/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:19:05 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/26 00:03:46 by jgirard-         ###   ########.fr       */
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
	if(child1 == -1)
		return(perror("fork"));
	if (!child1)
		childone(inputf, get_path, end);		
	child2 = fork();
	if(child2 == -1)
		return(perror("fork"));
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	childone(int infile, char **cmd1, int *fd)
{
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	
	return(EXIT_FAILURE);
}


