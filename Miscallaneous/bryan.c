#include <stdio.h>
#include <math.h>

int main(void)
{
    int uplim=10, digit=1, n_count=0, n_temp, comp;

    for(int n=1; n_count<20; n++)
    {
        n_temp=n, comp=0;

        if(n==uplim)
        {
            digit++;
            uplim *= 10;
        }

        for(int i=1; i<=digit; i++)
        {
            comp += pow(n_temp%10, digit);
            n_temp /= 10;
        }

        if(comp==n)
        {
            n_count++;
            printf("%d\n", n);
        }
    }

    return 0;
}
