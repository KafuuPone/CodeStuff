#include <stdio.h>
#include <stdlib.h>

// Calculate number of regions splitted by chords from dots on the circle

int main() {
    int x; // Final number of n
    printf("Value of x: "); scanf("%d", &x);
    unsigned long long a = 1;
    FILE* fptr = fopen("circle_chord.csv", "w");
    for(unsigned long long n=1; n<=x; n++) {
        printf("%5llu %15llu\n", n, a);
        fprintf(fptr, "%llu,%llu\n", n, a);
        for(unsigned long long k=1; k<=n; k++)
            a += (k-1)*(n-k)+1;
    }
    fclose(fptr);
    return 0;
}