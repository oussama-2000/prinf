/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:38:56 by oamkhou           #+#    #+#             */
/*   Updated: 2025/11/06 22:37:10 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_puthex(unsigned long n)
{
	char	*base = "0123456789abcdef";
    int count;

    count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16); // we increase the count here because each recursive call has a stack frame ,and the count will not be saved 
	count += write(1, &base[n % 16], 1);
    return (count);
}

int ft_putptr(void *ptr)
{
    long addr;
    int count;
    
    count = 0;
    addr = (long)ptr;
    if(!addr)
        return (ft_putstr("(nil)"));
    count += ft_putstr("0x");
    count += ft_puthex(addr);
    return (count);

}