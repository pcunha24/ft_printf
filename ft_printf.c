/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:30:00 by pedalexa          #+#    #+#             */
/*   Updated: 2023/11/13 13:23:36 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putpointer(va_arg(args, size_t)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexadecimal(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			len = len + ft_format(args, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/* 
int main (void)
{
	//Test without variables
	int result;
	int resultreal;

	result = 0;
	resultreal = 0;

	result = ft_printf("Teste\n");
	resultreal = ft_printf("Teste\n");

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);

	//Test 'c' format specifier (character)
	result = ft_printf("Character: %c\n", 'A');
	resultreal = printf("Character: %c\n", 'A');

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);
	result = 0;
	resultreal = 0;

	//Test 's' format specifier (string)
	result += ft_printf("String: %s\n", "Hello, world!");
	resultreal += printf("String: %s\n", "Hello, world!");

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);
	result = 0;
	resultreal = 0;


    // Test 'p' format specifier (pointer)
    void *ptr = (void *)0x12345678;
    result += ft_printf("Pointer: %p\n", ptr);
	resultreal += printf("Pointer: %p\n", ptr);

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);
	result = 0;
	resultreal = 0;


    // Test 'd' format specifier (decimal)
    result += ft_printf("Decimal: %d\n", 12345);
	resultreal += printf("Decimal: %d\n", 12345);

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);
	result = 0;
	resultreal = 0;


    // Test 'i' format specifier (integer)
    result += ft_printf("Integer: %i\n", -9876);
	resultreal += printf("Integer: %i\n", -9876);

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);
	result = 0;
	resultreal = 0;


    // Test 'u' format specifier (unsigned decimal)
    result += ft_printf("Unsigned Decimal: %u\n", 54321);
	resultreal += printf("Unsigned Decimal: %u\n", 54321);

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);
	result = 0;
	resultreal = 0;


    // Test 'x' format specifier (hexadecimal)
    result += ft_printf("Hexadecimal (lowercase): %x\n", 0xABCD);
	resultreal += printf("Hexadecimal (lowercase): %x\n", 0xABCD);

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);
	result = 0;
	resultreal = 0;



    // Test 'X' format specifier (hexadecimal, uppercase)
    result += ft_printf("Hexadecimal (uppercase): %X\n", 0x123);
	resultreal += printf("Hexadecimal (uppercase): %X\n", 0x123);

	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);
	result = 0;
	resultreal = 0;


    // Test '%' format specifier (percent symbol)
    result += ft_printf("Percent: %%\n");
	resultreal += printf("Percent: %%\n");




	printf("Total characters printed: %d\n", result);
	printf("Total characters printed: %d\n", resultreal);

	return 0;
}
 */