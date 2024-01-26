#include <stdio.h>

void solve(void);

int main(void)
{
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();

    return 0;
}

void solve(void)
{
    int k, n, x, output=1;
    scanf("%d %d", &k, &n);
    for(x=1; x<=k-1; x++)
        if(x*(x-1)>2*(n-k))
        {
            x--;
            break;
        }

    int i;
    for(i=1; i<=k; i++)
    {
        printf("%d ", output);
        if(i<=x)
            output += i;
        else
            output++;
    }
    printf("\n");
}
