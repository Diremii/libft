/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:49:43 by humontas          #+#    #+#             */
/*   Updated: 2024/10/14 11:11:35 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putchar_fd(n % 10 + '0');
	}
	else if (n < 10 && n != -2147483648)
		ft_putchar_fd(n + '0');
}
