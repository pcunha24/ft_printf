/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:27:19 by pedalexa          #+#    #+#             */
/*   Updated: 2023/11/08 14:27:12 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

char	*ft_strdup(const char *string)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc((ft_strlen(string) + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}
	while (string[i] != '\0')
	{
		dup[i] = string[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
