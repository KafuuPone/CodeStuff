#include <stdio.h>

void solve(void);

int main(void) {
    int i, t; scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();
    return 0;
}

void solve(void) {
    //input
    long long n, m; scanf("%lld %lld", &n, &m);
    //number of factors of 2 and 5
    int fac2 = 0, fac5 = 0;
    long long n_temp = n;
    for(; n_temp%2==0; fac2++) n_temp /= 2;
    for(; n_temp%5==0; fac5++) n_temp /= 5;
    //evaluate extra
    long long extra = 1;
    int i;
    if(fac2 > fac5)
        for(i=0; i<fac2-fac5 && extra*5 <= m; i++) extra *= 5;
    else
        for(i=0; i<fac5-fac2 && extra*2 <= m; i++) extra *= 2;
    //evaluate other
    long long other = 1, m_extra = m/extra;
    while(m_extra/other > 10) other *= 10;
    //evaluate k
    long long k = extra*other*(m/(extra*other));
    //print
    printf("%lld\n", n*k);
}