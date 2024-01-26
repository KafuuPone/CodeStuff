#include <stdio.h>

void solve(void);
int switchcount(long long a[], int k);
void printarr(const long long a[], int n); //remove later, test purposes

int main(void){
    int i, t; scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();

    return 0;
}

void solve(void){
    int n, m; scanf("%d %d", &n, &m);
    int a = n-m, b = m-1, i;
    long long r[a], l[b];
    //input r[a], l[b]
    int waste; scanf("%d", &waste);
    for(i=b-1; i>=0; i--){
        scanf("%lld", &l[i]);
        l[i] = -l[i];
    }
    for(i=0; i<a; i++)
        scanf("%lld", &r[i]);
    //printarr(r, a); printarr(l, b);//test
    //swtchcount of r + l
    printf("%d\n", switchcount(r, a)+switchcount(l, b));
}

int switchcount(long long a[], int k){
    int count = 0, i;
    //Setup array s
    long long s[k] = {a[0]};
    for(i=1; i<k; i++)
        s[i] = s[i-1]+a[i];
    printarr(s, k);//test
    while(1){
        //scan all a single <0
        int sw_i = -1;
        for(i=0; i<k; i++)
            if(s[i] < 0){
                sw_i = i;
                printf("subz = %d\n", a[sw_i]);//test
                break;
            }
        //loop if any<0
        if(sw_i == -1)
            break;
        else{
            //switch s_arr
            long long offset = -2*a[sw_i];
            for(i=sw_i; i<k; i++)
                s[i] += offset;
            //increment count
            count++;
            printarr(s, k); //remove later, test purposes
        }
    }
    return count;
}

void printarr(const long long a[], int n){
    int i;
    for(i=0; i<n; i++)
        printf("%lld ", a[i]);
    printf("\n");
}