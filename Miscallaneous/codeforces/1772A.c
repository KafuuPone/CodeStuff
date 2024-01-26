#include <Stdio.h>

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
    char str[4];
    scanf("%s", &str);
    printf("%d\n", (str[0]-'0')+(str[2]-'0'));
}
