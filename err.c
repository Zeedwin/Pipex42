/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 07:13:16 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/30 09:35:00 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	err_pipex(void)
{
	ft_putstr_fd("Use:\n./pipex file1 cmd1 cmd2 file2\n",2);
	return(EXIT_FAILURE);
}

int	bad_infile(char	*file)
{
	ft_putstr_fd("no file / directory found: ", 2);
	ft_putstr_fd((char *)file, 2);
	return (EXIT_FAILURE);
}
