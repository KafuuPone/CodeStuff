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
    int a[3], i;
    for(i=0; i<3; i++)
        scanf("%d", &a[i]);
    int sort = 1, temp;
    while(sort)
    {
        sort = 0;
        for(i=0; i<=1; i++)
        {
            if(a[i] > a[i+1])
            {
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                sort = 1;
            }
        }
    }
    printf("%d\n", a[1]);
}
