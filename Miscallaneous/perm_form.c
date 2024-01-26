#include <stdio.h>
#include <math.h>

int perms(int n, int k);

int main(void) {
    int n, k; scanf("%d %d", &n, &k);
    printf("%d", perms(n, k));
    return 0;
}

int perms(int n, int k) {
    int out = pow(2, n-k-1)*(n-k+2), r;
    for(r=k; r<n-k; r++)
        out -= perms(r, k)*pow(2, n-k-1-r);
    return out;
}