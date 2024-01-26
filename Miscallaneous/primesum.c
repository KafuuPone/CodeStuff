#include <stdio.h>

int prime(int);

int main(void)
{
    int n;
    for(n=2; n<= 100000; n+=2)
    {
        int temp, sum=0;
        for(temp=2; temp<=n/2; temp++)
            if(prime(temp)&&prime(n-temp))
                sum++;
        //printf("%d, %d\n", n, sum);

        FILE* f = fopen("number.csv", "a");  // open the file for writing
        if (f != NULL)                       // check for success
        {
            fprintf(f, "%d, %d\n", n, sum);            // write the number 42 as a string
            fclose(f);                       // close the file
            f = NULL;                        // set file handle to null since f is no longer valid
        }
    }

    return 0;
}

int prime(int n)
{
    int output = 1;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            output = 0;
            break;
        }
    }

    return output;
}
