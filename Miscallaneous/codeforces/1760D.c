//up then down means NO
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
    int n;
    scanf("%d", &n);

    int arr[n+1], i;
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    arr[n] = arr[n-1];

    int grad, up=0, valley=1;
    for(i=0; i<n; i++)
    {
        grad = arr[i+1]-arr[i];
        if(grad > 0)
            up = 1;
        if(up && grad<0)
        {
            valley = 0;
            break;
        }
    }

    printf("%s\n", valley?"YES":"NO");
}
