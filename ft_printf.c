/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:57:56 by oamkhou           #+#    #+#             */
/*   Updated: 2025/11/08 14:45:13 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char format, va_list args)
{
	int	n;

	n = 0;
	if (format == 'c')
		n += ft_putchar(va_arg(args, int));
	else if (format == 's')
		n += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		n += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		n += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		n += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		n += ft_putulhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		n += ft_putchar('%');
	else
	{
		n += ft_putchar('%');
		n += ft_putchar(format);
	}
	return (n);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, f);
	i = 0;
	count = 0;
	while (f[i])
	{
		if (write(1, "", 0) < 0)
			return (-1);
		if (f[i] == '%')
		{
			count += ft_format(f[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(f[i]);
		i++;
	}
	va_end(args);
	return (count);
}
