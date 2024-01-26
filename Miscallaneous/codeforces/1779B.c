#include <stdio.h>

void solve(void);

int main(void)
{
    int i, t; scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();

    return 0;
}

void solve(void)
{
    int n; scanf("%d", &n);
    if(n == 3)
        printf("NO\n");
    else
    {
        printf("YES\n");
        int a=1, b=-1, i;
        if(n%2 != 0)
        {
            a = (n-1)/2-1;
            b = (1-n)/2;
        }
        for(i=0; i<n; i++)
        {
            if(i%2 == 0)
                printf("%d ", a);
            else
                printf("%d ", b);
        }
        printf("\n");
    }
}