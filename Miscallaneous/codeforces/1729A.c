#include <stdio.h>
#include <math.h>

void solve(void);

int main(void)
{
    int t;
    scanf("%d", &t);

    int i;
    for(i=0; i<t; i++)
        solve();
}

void solve(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int time1, time2;
    time1 = (a-1);
    time2 = abs(b-c)+(c-1);

    if(time1<time2)
        printf("1\n");
    else if(time2<time1)
        printf("2\n");
    else
        printf("3\n");
}
