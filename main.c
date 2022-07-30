/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:19:28 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/28 22:38:36 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	if (argc != 5)
		return (err_pipex());
	if (!file_input_check(argv[1]))
		return (bad_infile(argv[1]));
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (infile < 0 || outfile < 0)
		return (EXIT_FAILURE);
	pipexu(infile, outfile, argv, envp);
	return (EXIT_SUCCESS);
}

