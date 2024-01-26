#include <stdio.h>

void solve(void);

int main(void) {
    int t, i; scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();
    return 0;
}

void solve(void) {
    //input and determine sum of available var and sum of all m and s
    int m, s; scanf("%d %d", &m, &s);
    int i, sum = s, arr_max = 0;
    for(i=0; i<m; i++) {
        int temp; scanf("%d", &temp);
        sum += temp;
        if(temp > arr_max)
            arr_max = temp;
    }
    //calculations
    int output = 0, n = arr_max, temp_sum = n*(n+1)/2;
    while(temp_sum <= sum) {
        if(temp_sum == sum) {
            output = 1;
            break;
        }
        n++; temp_sum += n;
    }
    //output print
    printf("%s\n", output?"YES":"NO");
}