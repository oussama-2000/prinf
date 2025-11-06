/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:57:56 by oamkhou           #+#    #+#             */
/*   Updated: 2025/11/06 15:47:14 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
// static int ft_is_format(char c)
// {
//     char *formats;
//     int i;
    
//     formats="cspdiuxX%";
//     i = 0;
    
//     while(formats[i] != '\0')
//     {
//         if(formats[i] == c)
//             return (1);
//         i++;
//     }
//     return (0);
    
// }
static int ft_format(char format, va_list args)
{
    int n;

    n = 0;
    if (format == 'c')
        n += ft_putchar(va_arg(args, int));
    else if (format == 's')
        n += ft_putstr(va_arg(args,char *));
    else if (format == 'p')
        n += ft_putptr(va_arg(args, void *));
    else if (format == 'd' || format == 'i')
        n += ft_putnbr(va_arg(args, int));
    else if (format == 'u')
        n += ft_putunbr(va_arg(args,unsigned int));
    else if (format == 'x' || format == 'X')
        n += ft_putulhex(va_arg(args, unsigned int),format);
    else if(format == '%')
        n += ft_putchar('%');
    return (n);
}
// ... ellipsis parameter
int ft_printf(const char *f, ...)
{
    va_list args;      // the list of arguments (hold the arguments list)
    va_start(args, f); // initialize the args list  (va_list)

    int i = 0;
    int arn = 0;
    while (f[i] != '\0')
    {
        if (f[i] == '%')
        {
            while(f[i + 1] == ' ')
                i++;
            arn += ft_format(f[i + 1], args);
            i++;
        }
        else
            arn += write(1, &f[i], 1);
        i++;
    }
    va_end(args);
    return (arn);
}

// int main()
// {
//     int count ;

//     count = 0;
//     void *ptr;

//     // count =printf("%X\n","hell");
//     count =ft_printf("the number is %% %d\n",-255);

//     printf("count :%d\n",count);

// }