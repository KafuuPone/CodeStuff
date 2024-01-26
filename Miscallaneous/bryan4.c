#include <stdio.h>

int prime(int);

int main(void)
{
    int n, result;

    printf("Input an even integer larger than 5: ");
    scanf("%d", &n);

    if(n>5 && n%2==0)
    {
        for(result=2; result<=n/2; result++)
            if(prime(result)&&prime(n-result))
                printf("%d %d\n", result, n-result);
    }
    else
        printf("Invalid input.");

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
