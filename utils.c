/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:56:58 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/30 12:08:19 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && len != 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && len > (i + j))
		{
			j++;
			if (ft_strlen(needle) == j)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < (n - 1) && s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*gnl_ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (0);
}

//