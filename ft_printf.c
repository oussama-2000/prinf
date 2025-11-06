/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:57:56 by oamkhou           #+#    #+#             */
/*   Updated: 2025/11/06 23:06:15 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
    else
    {
        n += ft_putchar('%');
        n += ft_putchar(format);
    }
    return (n);
}

int ft_printf(const char *f, ...)
{
    va_list args;
    va_start(args, f);

    int i = 0;
    int count = 0;
    

    while (f[i])
    {
        if (write(1, "", 0) < 0)
            return (-1);
        if (f[i] == '%')
        {
            while(f[i + 1] == ' ')
                i++;
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
#include <fcntl.h>
// int main()
// {
//     int count;

//     count = 0;
//     void *ptr;

//     // count += printf("%");
//     // printf("%rd\n",5);
//     // ft_printf("the character : %c\nthe string : %s\nthe number %d\nthe pointer %p\nthe u %u\nthe x %x\nthe X %X",'x',"hello",500,NULL,10,255,255);

//     // fclose(stdout);
//     // int check = ft_printf("hello");
//     // fprintf(stderr, "%d\n", check);
// }


#include <limits.h>
int main(void)
{
    int ret_ft, ret_org;
    void *ptr = (void *)0x7ffeefbff618;
    void *null_ptr = NULL;

    printf("========== BASIC TESTS ==========\n");

    // %c
    ret_org = printf("ORG: char: [%c]\n", 'A');
    ret_ft = ft_printf("FT : char: [%c]\n", 'A');
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %s
    ret_org = printf("ORG: string: [%s]\n", "Hello World!");
    ret_ft = ft_printf("FT : string: [%s]\n", "Hello World!");
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %s (NULL)
    ret_org = printf("ORG: null string: [%s]\n", (char *)NULL);
    ret_ft = ft_printf("FT : null string: [%s]\n", (char *)NULL);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %p
    ret_ft = ft_printf("FT : pointer: [%p]\n", ptr);
    ret_org = printf("ORG: pointer: [%p]\n", ptr);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %p (NULL)
    ret_org = printf("ORG: null pointer: [%p]\n", null_ptr);
    ret_ft = ft_printf("FT : null pointer: [%p]\n", NULL);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %d
    ret_org = printf("ORG: decimal: [%d]\n", 12345);
    ret_ft = ft_printf("FT : decimal: [%d]\n", 12345);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %i
    ret_org = printf("ORG: integer: [%i]\n", -54321);
    ret_ft = ft_printf("FT : integer: [%i]\n", -54321);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %u
    ret_org = printf("ORG: unsigned: [%u]\n", 4294967295u);
    ret_ft = ft_printf("FT : unsigned: [%u]\n", 4294967295u);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %x
    ret_org = printf("ORG: hex lower: [%x]\n", 3735928559u);
    ret_ft = ft_printf("FT : hex lower: [%x]\n", 3735928559u);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %X
    ret_org = printf("ORG: hex upper: [%X]\n", 3735928559u);
    ret_ft = ft_printf("FT : hex upper: [%X]\n", 3735928559u);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // %%
    ret_org = printf("ORG: percent: [%%]\n");
    ret_ft = ft_printf("FT : percent: [%%]\n");
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    printf("========== EDGE CASES ==========\n");

    // INT_MIN / INT_MAX
    ret_org = printf("ORG: INT_MIN: [%d], INT_MAX: [%d]\n", INT_MIN, INT_MAX);
    ret_ft = ft_printf("FT : INT_MIN: [%d], INT_MAX: [%d]\n", INT_MIN, INT_MAX);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // Zero values
    ret_org = printf("ORG: zero values: d[%d] u[%u] x[%x] X[%X]\n", 0, 0, 0, 0);
    ret_ft = ft_printf("FT : zero values: d[%d] u[%u] x[%x] X[%X]\n", 0, 0, 0, 0);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    // Mix multiple specifiers
    ret_org = printf("ORG: mix: char[%c] str[%s] int[%d] hex[%x] ptr[%p] percent[%%]\n",
                     'Z', "MixTest", 123, 255, &ptr);
    ret_ft = ft_printf("FT : mix: char[%c] str[%s] int[%d] hex[%x] ptr[%p] percent[%%]\n",
                       'Z', "MixTest", 123, 255, &ptr);
    printf("Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_org);

    printf("========== END OF TEST ==========\n");
    return 0;
}