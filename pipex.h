/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:19:10 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/30 12:12:15 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**get_path(char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*gnl_ft_strchr(char *s, int c);
int		file_input_check(char *file);
int		bad_infile(char	*file);
int		err_pipex(void);
size_t	ft_strlen(const char	*str);  
void	pipexu(int inputf, int outputf, char **arg, char **env);
char	**find_cmd(char const	*arg_cmd,	char	**envp);
void	ft_putstr_fd(char *s, int fd);
int		cmd1(int infile, char **cmd1, int *fd);
int		cmd2(int outfile, char **cmd2, int *fd);

# define COMMAND_NOT_FOUND 127

#endif
