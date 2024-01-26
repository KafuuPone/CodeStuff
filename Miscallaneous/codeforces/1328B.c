#include <stdio.h>

void solve(void);

int main(void)
{
    int i, t;
    scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();
    
    return 0;
}

void solve(void)
{
    int n, k, b;
    scanf("%d %d", &n, &k);
    for(b=1; k>0; b++)
        k -= b;
    k = -k; b--;

    int i;
    for(i=1; i<=n; i++)
    {
        if(i==n-b || i==n-b+k+1)
            printf("b");
        else
            printf("a");
    }
    printf("\n");
}