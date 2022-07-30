/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:42:11 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/30 10:51:45 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	joinslash(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][ft_strlen(envp[i]) - 1] != '/')
			envp[i] = ft_strjoin(envp[i], "/");
		i++;
	}
}

char	**get_path(char **envp)
{
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			if (!path)
				return (NULL);
			joinslash(path);
			break ;
		}
		i++;
	}
	return (path);
}

static int	get_cmd_path(char  **cmd, char **envp)
{
	char	**path;
	char	*tmp;
	int		i;

	if (file_input_check(*cmd))
		return(1);
	path = get_path(envp);
	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], *cmd);
		if(file_input_check(tmp))
		{
			free(*cmd);
			*cmd = tmp;
			return (1);
		}
		free(tmp);
		i++;
	}
	return (COMMAND_NOT_FOUND);
}

char	**find_cmd(char const	*arg_cmd,	char	**envp)
{
	char	**cmd;

	cmd	= ft_split(arg_cmd, ' ');
	if (cmd == NULL)
		return (NULL);
	if (get_cmd_path(cmd, envp) == 0)
	{
		return(NULL);
	}
	return (cmd);
}
