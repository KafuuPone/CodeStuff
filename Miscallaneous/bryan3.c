#include <stdio.h>

int main(void)
{
    int n=0, m, sum=0;

    printf("Input positive integer m: ");
    scanf("%d", &m);

    while(sum < m)
    {
        n++;
        sum += n*(n+1)*(n+2);
    }

    printf("%d", n);

    return 0;
}
