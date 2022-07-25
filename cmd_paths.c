/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:42:11 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/26 00:06:08 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static int	get_cmd_path(char **cmd, char **envp) //change static int return CMD Not Found
{
	char	**path;
	char	*tmp;
	int		i;

	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path)
	}
	
	return (COMMAND_NOT_FOUND);
}

static void	joinslash(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!gnl_ft_strchr(*envp, '/'))
			envp[i] = ft_strjoin(envp[i], "/");
		i++;
	}
}
