/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:58:33 by joandre-          #+#    #+#             */
/*   Updated: 2024/09/23 19:17:44 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nbr(unsigned long long n, int *len)
{
	if (n / 10)
	{
		print_nbr(n / 10, len);
		print_nbr(n % 10, len);
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + '0', STDOUT_FILENO);
		++(*len);
	}
}

static void	print_hex(unsigned long long n, const char specifier,
	char *hex, int *len)
{
	if (n >= 16)
	{
		print_hex(n / 16, specifier, hex, len);
		print_hex(n % 16, specifier, hex, len);
	}
	if (n < 10)
		hex[(*len)++] = n + '0';
	else if (n < 16)
	{
		if (specifier == 'x' || specifier == 'p')
			hex[(*len)++] = n - 10 + 'a';
		else if (specifier == 'X')
			hex[(*len)++] = n - 10 + 'A';
	}
}

int	ft_printhex(unsigned long long n, const char specifier)
{
	int		len;
	char	hex[17];

	len = 0;
	ft_bzero(&hex, 17);
	if (specifier == 'x' || specifier == 'X')
		print_hex((unsigned int)n, specifier, hex, &len);
	else if (specifier == 'p')
	{
		if (n == 0)
		{
			ft_putstr_fd("(nil)", STDOUT_FILENO);
			return (5);
		}
		ft_putstr_fd("0x", STDOUT_FILENO);
		print_hex(n, specifier, hex, &len);
		len += 2;
	}
	ft_putstr_fd(hex, STDOUT_FILENO);
	return (len);
}

int	ft_printnbr(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		++len;
		print_nbr(n * -1, &len);
	}
	else
		print_nbr(n, &len);
	return (len);
}

int	ft_printstr(const char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		return (6);
	}
	ft_putstr_fd((char *)s, STDOUT_FILENO);
	return (ft_strlen(s));
}
