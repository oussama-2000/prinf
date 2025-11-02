#include<stdio.h>
#include <stdarg.h>

int sum(int a,...)
{
    va_list args; // macro
    va_start(args,a);

    int s = a;
    int i = 0;
    int x = va_arg(args, int);

    while(x != 0)
    {
        s+=x;
        x = va_arg(args, int);
        // printf("[%d]\n",x);
    }
    va_end(args);
    return s;
}


int main()
{
    int numbers[]={1,2,3,4,5,6};
    printf("sum is : %d\n",sum(1,2,3,4,5,6,0));
    char str[]="hello";
    printf("%d %s %p",4 ,str,str,str);
}