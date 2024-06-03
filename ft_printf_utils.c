/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:58:33 by joandre-          #+#    #+#             */
/*   Updated: 2024/06/01 02:28:20 by joandre-         ###   ########.fr       */
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

static void	print_hex(unsigned long long n, const char specifier, int *len)
{
	if (n >= 16)
	{
		print_hex(n / 16, specifier, len);
		print_hex(n % 16, specifier, len);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', STDOUT_FILENO);
		++(*len);
	}
	else if (n < 16)
	{
		if (specifier == 'x' || specifier == 'p')
			ft_putchar_fd(n - 10 + 'a', STDOUT_FILENO);
		else if (specifier == 'X')
			ft_putchar_fd(n - 10 + 'A', STDOUT_FILENO);
		++(*len);
	}
}

int	ft_printhex(unsigned long long n, const char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'x' || specifier == 'X')
		print_hex(n, specifier, &len);
	else if (specifier == 'p')
	{
		if (n == 0)
		{
			ft_putstr_fd("(nil)", STDOUT_FILENO);
			return (5);
		}
		ft_putstr_fd("0x", STDOUT_FILENO);
		len = 2;
		print_hex(n, specifier, &len);
	}
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
