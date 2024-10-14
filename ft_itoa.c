/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:05:57 by humontas          #+#    #+#             */
/*   Updated: 2024/10/14 11:10:03 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_number(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_count_number(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (i < ft_count_number(n))
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
