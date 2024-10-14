/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:04:36 by humontas          #+#    #+#             */
/*   Updated: 2024/10/14 11:06:19 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*tab;
	size_t	i;

	if (!nmeb || !size)
		return (NULL);
	tab = malloc(nmeb *(size));
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
