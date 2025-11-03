#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int ft_format(char format, va_list args)
{
    char formats[] = "cspdiuxX%";
    int n;

    n = 0;
    if (format == 'c')
        n += putchar(va_arg(args, int));
    else if (format == 's')
        n += puts(va_arg(args, char *));
    else
        n += write(1, &format, 1);
    return (n);
}
// ... ellipsis parameter
int ft_printf(const char *f, ...)
{
    va_list args;      // the list of arguments (hold the arguments list)
    va_start(args, f); // initialize the listargs (va_list)

    // int x = va_arg(args, int); // reading the list arguments
    int i = 0;
    int arn = 0;
    while (f[i] != '\0')
    {
        if (f[i] == '%')
        {
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

int main()
{
    ft_printf("ahmed [%s]","x");
}