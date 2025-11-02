#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int ft_isformat(const char *str, int i)
{
    char formats[] = "cspdiuxX%";
    int j = 0;
    if (str[i] == '%')
    {
        while(formats[j])
        {
            if(str[i + 1] == formats[j])
            {
                return (1);
            }
            j++;
        }
    }
    return (0);
}
// ... ellipsis parameter
int ft_printf(const char *f,...)
{
    va_list args; // the list of arguments (hold the arguments list)
    va_start(args, f); //initialize the listargs (va_list) 

    // int x = va_arg(args, int); // reading the list arguments
    // printf("first argument [%d]\n",x);
    // x++;
    // printf("first argument [%d]\n",x);


    int i = 0;
    int arn = 0;
    while (f[i] != '\0')
    {
        if (ft_isformat(f,i))
            arn++;
        else 
            arn += write(1, &f[i], 1);
        i++;
    }
    va_end(args);
    return (arn);
}

int main()
{
    printf("%d\n",ft_printf("ahmed\n",1,2,3));

}