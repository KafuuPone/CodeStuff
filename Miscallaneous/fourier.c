#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

double a_coeff(const double func[], int n, int sep); /*n >= 1*/
double b_coeff(const double func[], int n, int sep); /*n >= 0*/
void plot(int len, const double a[], const double b[], int n);

int main(void)
{
    int i, n;
    printf("Input even number of values: ");
    scanf("%d", &n);
    double func[n+1];
    for(i=1; i<=n; i++)
    {
        printf("f(x%d) = ", i);
        scanf("%lf", &func[i-1]);
    }
    func[n] = func[0];

    double a[n/2+1], b[n/2+1];
    for(i=0; i<=n/2; i++)
    {
        a[i] = a_coeff(func, i, n);
        b[i] = b_coeff(func, i, n);
    }

    plot(200, a, b, n/2);

    return 0;
}

double a_coeff(const double func[], int n, int sep)
{
    double temp[sep+1], output = 0;
    int i;
    for(i=0; i<=sep; i++)
    {
        double t = i*2*PI/sep;
        temp[i] = func[i]*cos(n*t);
    }
    for(i=0; i<=sep-1; i++)
        output += temp[i]+temp[i+1];
    output /= sep;
    if(n==0)
        output /= 2;
    return output;
}

double b_coeff(const double func[], int n, int sep)
{
    double temp[sep+1], output = 0;
    int i;
    for(i=0; i<=sep; i++)
    {
        double t = i*2*PI/sep;
        temp[i] = func[i]*sin(n*t);
    }
    for(i=0; i<=sep-1; i++)
        output += temp[i]+temp[i+1];
    output /= sep;
    return output;
}

void plot(int len, const double a[], const double b[], int n)
{
    int i, j;
    double x, fx;
    for(i=0; i<len; i++)
    {
        x = i*2*PI/len;
        fx = a[0];
        for(j=1; j<=n; j++)
            fx += a[j]*cos(j*x)+b[j]*sin(j*x);

        FILE* f = fopen("fourier.csv", "a");
        if (f != NULL)
        {
            fprintf(f, "%lf, %lf\n", x, fx);
            fclose(f);
            f = NULL;
        }
    }
}
