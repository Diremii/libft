/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:40:53 by humontas          #+#    #+#             */
/*   Updated: 2024/10/14 14:26:33 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*nav;
	int		count;

	nav = lst;
	count = 0;
	while (nav)
	{
		nav = nav->next;
		count++;
	}
	return (count);
}
