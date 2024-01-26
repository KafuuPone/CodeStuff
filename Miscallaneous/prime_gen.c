#include <stdio.h>

int prime(int);

int main(void)
{
    for(int i=2; ; i++)
        if(prime(i))
            printf("%d\n", i);

    return 0;
}

int prime(int n)
{
    int output = 1;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            output = 0;
            break;
        }
    }

    return output;
}
