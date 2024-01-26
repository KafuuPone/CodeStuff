#include <iostream>
#include <cmath>

#define M 3.24682e5

using namespace std;

double f(double x) {
    return pow(x, 5)-2*pow(x, 4)+pow(x, 3)-(1+1/M)*pow(x, 2)+2*x-1;
}

double fprime(double x) {
    return 5*pow(x, 4)-8*pow(x, 3)+3*pow(x, 2)-2*(1+1/M)*x+2;
}

int main() {
    double x = 2;
    for(int i=0; i<500; i++) {
        x -= f(x)/fprime(x);
        printf("%lf\n", x);
    }
    
    return 0;
}