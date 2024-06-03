/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:23:16 by joandre-          #+#    #+#             */
/*   Updated: 2024/06/03 21:44:56 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printhex(unsigned long long n, const char specifier);
int	ft_printnbr(long long n);
int	ft_printstr(const char *s);
int	ft_printf(const char *format, ...);

#endif
