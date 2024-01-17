/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:13:25 by pedalexa          #+#    #+#             */
/*   Updated: 2023/09/17 04:34:33 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		else
		{
			ft_putchar('-');
			n = -n;
		}
	}
	if (n > 9)
	{
		print_nbr(n / 10);
		print_nbr(n % 10);
	}
	else
	{
		ft_putchar(48 + n);
	}
}

int	ft_putnbr(int n)
{
	int	count;
	int	nr;

	count = 0;
	nr = n;
	print_nbr(n);
	if (nr < 0)
	{
		count = 1;
		nr = -nr;
	}
	while (nr != 0)
	{
		nr = nr / 10;
		count++;
	}
	return (count);
}
/*
int main ()
{
	int nb = 1234;
	printf(" return value: %d", ft_putnbr(nb));
	return 0;
}
*/
