/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 07:38:47 by humontas          #+#    #+#             */
/*   Updated: 2024/10/14 11:08:55 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	k = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] != c && tmp == 0)
		{
			tmp = 1;
			k++;
		}
		else if (s[i] == c)
		{
			tmp = 0;
		}
		i++;
	}
	return (k);
}

static char	*fill_word(char *str, int i, int j)
{
	char	*substr;
	int		l;

	l = 0;
	substr = malloc ((j - i + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < j)
	{
		substr[l] = str[i];
		i++;
		l++;
		}
	return (substr);
}
static void	ft_free(char *split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split);
		i++;
		}
	free(split);
}
static void	init_var(size_t *i, int *j, int *k)
{
	*i = 0;
	*j = -1;
	*k = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	int		j;
	int		k;

	int_var(&i, &j, &k);
	split = ft_calloc((count_word((char *)s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && j < 0)
			j = i;
		else if ((s[i] == c || i == ft_strlen(s)) && j >= 0)
		{
		split[k] = fill_word((char *)s, j, i);
			if (!(split[k]))
				return (NULL);
			j = -1;
			k++;
		}
		i++;
	}
	return (split);
}
