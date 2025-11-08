/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:00:44 by oamkhou           #+#    #+#             */
/*   Updated: 2025/11/08 14:48:56 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putulhex(unsigned int n, char format)
{
	char	*lbase;
	char	*ubase;
	int		count;

	lbase = "0123456789abcdef";
	ubase = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_putulhex((n / 16), format);
	if (format == 'x')
		count += write(1, &lbase[n % 16], 1);
	else
		count += write(1, &ubase[n % 16], 1);
	return (count);
}
