/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:00:44 by oamkhou           #+#    #+#             */
/*   Updated: 2025/11/06 14:20:35 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putulhex(int n, char format)
{

	char	*lbase = "0123456789abcdef";
	char	*ubase = "0123456789ABCDEF";
    int count;
    unsigned int nb;

    nb =(unsigned int)n;
    count = 0;
	if (nb >= 16)
		count += ft_putulhex((nb / 16),format);
    if (format == 'x')
	    count += write(1, &lbase[nb % 16], 1);
    else
	    count += write(1, &ubase[nb % 16], 1);
    return (count);
}