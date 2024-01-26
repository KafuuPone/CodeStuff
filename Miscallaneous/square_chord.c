#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10000000

double* point(int rand1, int rand2) {
    double* p = (double*)malloc(2*sizeof(double));
    int side = rand1%4;
    double a = (double)rand2/RAND_MAX;
    switch(side) {
        case 0:
            p[0] = a; p[1] = 0;
            break;
        case 1:
            p[0] = 0; p[1] = a;
            break;
        case 2:
            p[0] = a; p[1] = 1;
            break;
        case 3:
            p[0] = 1; p[1] = a;
            break;
    }
    return p;
}

int main() {
    srand((unsigned)time(NULL));
    int dist_gte = 0;
    for(int i=1; i<=N; i++) {
        double *p1, *p2;
        p1 = point(rand(), rand());
        p2 = point(rand(), rand());
        double dist_sqr = (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
        if(dist_sqr >= 1)
            dist_gte++;
    }
    printf("%lf\n", (double)dist_gte/N);
    return 0;
}