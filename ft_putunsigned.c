/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:05:34 by pedalexa          #+#    #+#             */
/*   Updated: 2024/01/21 22:58:05 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_unlen(n);
	if (!len)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_putunsigned(int n)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = ft_utoa(n);
	len = ft_unlen(n);
	if (n == 0)
	{
		write (1, "0", 1);
		free(str);
		return (1);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (len);
}
