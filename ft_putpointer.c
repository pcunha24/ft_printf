/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:58:30 by pedalexa          #+#    #+#             */
/*   Updated: 2023/11/13 13:31:09 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(size_t ptr)
{
	int	len;

	len = 2;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static void	ft_printpointer(size_t ptr)
{
	int	numb;

	if (ptr >= 16)
	{
		ft_printpointer(ptr / 16);
		ft_printpointer(ptr % 16);
	}
	else
	{
		if (ptr >= 10)
		{
			numb = 'a' + ptr - 10;
			write (1, &numb, 1);
		}
		else
		{
			numb = '0' + ptr;
			write (1, &numb, 1);
		}
	}
}

int	ft_putpointer(size_t ptr)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	ft_printpointer(ptr);
	return (ft_ptr_len(ptr));
}
/*
int main (void)
{
	int a = 4;
	int *ptr = &a;
	int	len = ft_putpointer((size_t)ptr);
	printf("\n%d\n", len);
	return (0);
}
*/