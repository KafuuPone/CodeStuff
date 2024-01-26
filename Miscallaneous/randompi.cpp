#include<iostream>
#include<iomanip>
#include<random>
#include<cmath>
using namespace std;

long double fRand(long double fMin, long double fMax)
{
    long double f = (long double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main() {
	long double count, total;
	int a = 0;
	count = total = 0;
	long double piapprox;
	while(true) {
		long double x = fRand(0, 1);
		long double y = fRand(0, 1);
		total++; a++;
		count += (x*x+y*y < 1);
		piapprox = count*4/total;
		if(a%100 == 0) cout << setprecision(10) << piapprox << ' ' << abs(piapprox/M_PI-1) << endl;
	}
}