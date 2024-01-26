#include <stdio.h>

void solve(void);

int main(void) {
    int t, i; scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();
    return 0;
}

void solve(void) {
    //input, a>=b
    int l, r, x, a, b;
    scanf("%d %d %d %d %d", &l, &r, &x, &a, &b);
    //swap if b>a
    if(b > a) {
        int temp = b;
        b = a;
        a = temp;
    }
    //calculation
    int steps;
    if (a == b)
        steps = 0;
    else if(a-b >= x)
        steps = 1;
    else if(r>=a+x || l<=b-x)
        steps = 2;
    else if(r>=b+x && l<=a-x)
        steps = 3;
    else
        steps = -1;
    //print ans
    printf("%d\n", steps);
}