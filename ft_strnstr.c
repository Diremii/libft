/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:49:48 by humontas          #+#    #+#             */
/*   Updated: 2024/10/14 11:05:38 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_str;
	char	*little_str;

	i = 0;
	j = 0;
	big_str = (char *) big;
	little_str = (char *) little;
	if (!big || !little)
		return (NULL);
	while (big_str[i] != '\0' && i < len)
	{
		if (big_str[i] == little_str[j])
		{
			if (big_str[i] >= little_str[j])
				return (&big_str[+i]);
			i++;
			j++;
		}
		i++;
	}
	return (NULL);
}
