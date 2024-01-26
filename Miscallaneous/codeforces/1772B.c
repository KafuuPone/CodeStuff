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
    int a[4], i;
    for(i=0; i<4; i++)
        scanf("%d", &a[i]);
    int row, col;
    row = (a[0]-a[1])*(a[2]-a[3]);
    col = (a[0]-a[2])*(a[1]-a[3]);
    printf("%s\n", (row>0 && col>0)?"YES":"NO");
}
