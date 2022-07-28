/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 07:13:16 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/28 20:50:54 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_cmd(char	*arg_cmd,	char	**envp)
{
	char	**cmd;
	
	cmd	= ft_split(arg_cmd, ' ');
	if (!cmd)
		return (NULL);
	if (get_cmd_path(cmd, envp) == 0)
		return(NULL);
	return (cmd);
}


