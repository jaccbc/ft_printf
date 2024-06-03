/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:11:49 by joandre-          #+#    #+#             */
/*   Updated: 2024/05/31 22:56:40 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	route_specifier(va_list fsrc, const char specifier)
{
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (ft_printhex(va_arg(fsrc, unsigned long long), specifier));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_printnbr(va_arg(fsrc, int)));
	else if (specifier == 'u')
		return (ft_printnbr(va_arg(fsrc, unsigned int)));
	else if (specifier == 's')
		return (ft_printstr(va_arg(fsrc, char *)));
	else if (specifier == 'c')
		ft_putchar_fd(va_arg(fsrc, int), STDOUT_FILENO);
	else if (specifier == '%')
		ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	fsrc;
	size_t	i;
	int		len;

	if (!format)
		return (-1);
	va_start(fsrc, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += route_specifier(fsrc, format[++i]);
			++i;
		}
		else
		{
			ft_putchar_fd(format[i++], STDOUT_FILENO);
			++len;
		}
	}
	va_end(fsrc);
	return (len);
}
