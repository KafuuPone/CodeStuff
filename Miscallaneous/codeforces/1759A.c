#include <stdio.h>

void solve(void);

int main(void) {
    int t, i; scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();
    return 0;
}

void solve(void) {
    char str[51] = {}, yes[] = "Yes";
    scanf("%s", &str);
    int output = 1, i, j;
    for(i=0; i<3; i++)
        if(str[0] == yes[i])
            break;
    for(j=0; str[j]!=0; i=(i+1)%3, j++)
        if(str[j] != yes[i]) {
            output = 0;
            break;
        }
    printf("%s\n", output?"YES":"NO");
}