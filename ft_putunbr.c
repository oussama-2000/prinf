/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:51:00 by oamkhou           #+#    #+#             */
/*   Updated: 2025/11/06 14:45:45 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putunbr(unsigned int n)
{
  int count;

  count = 0;
  if (n >= 10)
    count += ft_putnbr(n / 10);
  count += ft_putchar((n % 10) + '0');
  return (count);
}