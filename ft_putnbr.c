/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:13:25 by pedalexa          #+#    #+#             */
/*   Updated: 2024/01/21 22:59:42 by pedalexa         ###   ########.fr       */
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
	if (nr == 0)
		return (1);
	else if (nr < 0)
	{
		count++;
		nr = -nr;
	}
	while (nr != 0)
	{
		nr = nr / 10;
		count++;
	}
	return (count);
}

/* int main ()
{
	int ret_value;

    ret_value = ft_putnbr(0);
	printf("\nreturn value: %d\n", ret_value);
	return 0;
} */
