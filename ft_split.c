/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:04:29 by humontas          #+#    #+#             */
/*   Updated: 2024/10/15 10:07:01 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] != c && tmp == 0)
		{
			tmp = 1;
			j++;
		}
		else if (s[i] == c)
		{
			tmp = 0;
		}
		i++;
	}
	return (j);
}

static char	*fill_word(char *str, int i, int w_split)
{
	char	*substr;
	int		l;

	l = 0;
	substr = malloc ((i - w_split + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (w_split < i)
	{
		substr[l] = str[w_split];
		w_split++;
		l++;
	}
	return (substr);
}

static void	*ft_free(char **split, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(split[j]);
		i++;
	}
	free(split);
	return (NULL);
}

static void	init_var(size_t *i, int *j, int *w_split)
{
	*i = 0;
	*j = 0;
	*w_split = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	int		j;
	int		w_split;

	init_var(&i, &j, &w_split);
	split = calloc((count_word((char *)s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && w_split < 0)
			w_split = i;
		else if ((s[i] == c || i == ft_strlen(s)) && w_split >= 0)
		{
			split[j] = fill_word((char *)s, i, w_split);
			if (!(split[j]))
				ft_free(split, j);
			w_split = -1;
			j++;
		}
		i++;
	}
	return (split);
}
