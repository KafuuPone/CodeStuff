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
    int n;
    scanf("%d", &n);
    char str[n+1];
    scanf("%s", &str);

    int i, output = -1;
    for(i=1; i<n; i++)
    {
        if(str[i-1]=='L' && str[i]=='R')
        {
            output = i;
            break;
        }
        else if(str[i-1]=='R' && str[i]=='L')
        {
            output = 0;
            break;
        } 
    }

    printf("%d\n", output);
}