/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 07:27:02 by jgirard-          #+#    #+#             */
/*   Updated: 2022/07/28 07:29:47 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc((sizeof(char)) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == 0)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_wcount(char const *s, char c)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wc++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (wc);
}

static char	*ft_cut(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		i;
	int		j;

	j = 0;
	i = 0;
	splited = malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	while (s[i])
	{
		if (s[i] != c)
		{
			splited[j++] = ft_cut(s + i, c);
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	splited[j] = NULL;
	return (splited);
}