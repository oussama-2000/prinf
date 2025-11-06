#include <stdarg.h>
#include <stdio.h>

int count_chck(int n, ...)
{
    va_list args;

    int count = 0;
    int i = 0;
    va_start(args, n);
    while (i < n)
    {
        count += va_arg(args, int);
        i++;
    }
    return (count / n);
}
int main()
{
    int i = count_chck(3, 10, 15, 20);
    printf("%d\n", i);
}