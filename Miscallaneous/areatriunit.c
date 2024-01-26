#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double triarea(double*);

int main(void)
{
    int i, n;
    double sum=0, coord[6];

    scanf("%d", &n);

    srand((unsigned)time(NULL));
    for(i=1; i<=n; i++)
    {
        int j;
        for(j=0; j<6; j++)
            coord[j] = (double)rand()/RAND_MAX;
        sum += triarea(coord);

        printf("x1=%.3lf x2=%.3lf x3=%.3lf y1=%.3lf y2=%.3lf y3=%.3lf", coord[0], coord[1], coord[2], coord[3], coord[4], coord[5]);
        printf("     A=%lf Avg=%lf\n", triarea(coord), sum/i);
    }

    return 0;
}

double triarea(double* coord)
{
    double arr[6];
    int i;
    for(i=0; i<6; i++)
        arr[i] = *(coord+i);
    return 0.5*fabs(arr[0]*(arr[4]-arr[5])+arr[1]*(arr[5]-arr[3])+arr[2]*(arr[3]-arr[4]));
}
