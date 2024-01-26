#include <stdio.h>

int main(void)
{
    //Get input for n
    int n;
    printf("Input a positive integer n: ");
    scanf("%d", &n);

    //Generate matrix a
    int a[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 || j==0 || i==n-1 || j==n-1)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    //Print matrix a
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
