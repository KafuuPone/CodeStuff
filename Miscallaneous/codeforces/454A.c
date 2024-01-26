#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, k;
    scanf("%d", &n);
    k = (n-1)/2;

    int i, j;
    for(i=-k; i<=k; i++)
    {
        for(j=-k; j<=k; j++)
            printf("%c", (abs(i)+abs(j)>k)?'*':'D');
        printf("\n");
    }

    return 0;
}
