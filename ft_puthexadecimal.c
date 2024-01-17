/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:38:16 by pedalexa          #+#    #+#             */
/*   Updated: 2023/11/13 13:33:20 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_puthexadecimal(unsigned int n, const char format)
{
	int	numb;

	if (n >= 16)
	{
		ft_puthexadecimal(n / 16, format);
		ft_puthexadecimal(n % 16, format);
	}
	else
	{
		if (n >= 10)
		{
			if (format == 'X')
				numb = 'A' + n - 10;
			if (format == 'x')
				numb = 'a' + n - 10;
			write (1, &numb, 1);
		}
		else
		{
			numb = '0' + n;
			write (1, &numb, 1);
		}
	}
	return (ft_hexlen(n));
}
/*
int main (void)
{
	int n = 15;
	int len = ft_puthexadecimal(n, 'x');
	printf("\n%d", len);
	return (0);
}
*/