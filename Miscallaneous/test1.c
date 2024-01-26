#include <stdio.h>

void get_poly(double[]);
double poly(double, double[]);

int main(void)
{
    double coef[4];
    get_poly(coef);
    printf("%lf", poly(5, coef));

    return 0;
}

void get_poly(double coef[4])
{
	int i;
	for(i=0; i<4; i++)
		scanf("%lf", &coef[i]);
}

double poly(double x, double coef[4])
{
	int result = 0, i;
	for(i=0; i<4; i++)
	{
		int temp = 1, j;
		for(j=0; j<3-i; j++)
			temp *= x;
		result += coef[i]*temp;
	}
	return result;
}
