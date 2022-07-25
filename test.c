/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:19:28 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/09 20:09:19 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_path;
	char	*cmd;
	char	*opts;

	opts[3] = {"ls", "-la", NULL};
	cmd = "ls";
	(void)argc;
	(void)argv;
	cmd_path = get_cmd_path(cmd, envp);
	execve("/bin/ls", opts, envp);
	return (0);
}

char	get_cmd_path(char cmd, char envp)
{ 

}
