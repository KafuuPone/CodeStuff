#include <stdio.h>

int main(void)
{
    double pi_4 = 0;

    for(int i=1; ; i++)
    {
        if(i%2==0)
            pi_4 -= 1.0/(2*i-1);
        else
            pi_4 += 1.0/(2*i-1);

        printf("%.10lf\n", pi_4*4);
    }

    return 0;
}
