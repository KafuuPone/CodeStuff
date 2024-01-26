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
    int n, i;
    scanf("%d", &n);
    char str[n+1], max = 'a';
    scanf("%s", &str);
    for(i=0; i<n; i++)
        if(str[i] > max)
            max = str[i];
    printf("%d\n", max-'a'+1);
}
