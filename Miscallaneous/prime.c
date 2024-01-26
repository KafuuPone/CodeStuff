#include <stdio.h>

long long prime(long long x);
long long min_prime_div(long long num);
void print_factor(long long num);

int main(void) {
    long long num; scanf("%lld", &num);
    print_factor(num);
    return 0;
}

long long prime(long long x) {
    long long i;
    for(i=2; i<x; i++)
        if(x%i == 0)
            return 0;
    return 1;
}

long long min_prime_div(long long num) {
    long long i;
    for(i=2; i<=num; i++)
        if(num%i==0 && prime(i))
                break;
    return i;
}

void print_factor(long long num) {
    printf("%lld = ", num);
    while(num != 1) {
        long long factor = min_prime_div(num);
        num /= factor;
        printf("%lld", factor);
        if(num != 1)
            printf("*");
    }
    printf("\n");
}