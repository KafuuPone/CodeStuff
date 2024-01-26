#include <stdio.h>
#include <math.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);

    double sum = m;
    int i;
    for(i=1; i<=m-1; i++)
        sum -= pow((double)i/m, n);

    printf("%f", sum);

    return 0;
}
