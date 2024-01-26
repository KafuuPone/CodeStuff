#include <cmath>
#include "classes.h"

#include "vect.h"

//absolute value of a vector
double vectlen(vect v) {
    double x = v.x, y = v.y, z = v.z;
    return pow(x*x+y*y+z*z, 0.5);
}

//vector addition
vect add(vect v1, vect v2) {
    vect sum = {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z};
    return sum;
}

//vector subtraction
vect subtract(vect v1, vect v2) {
    vect diff = {v1.x-v2.x, v1.y-v2.y, v1.z-v2.z};
    return diff;
}

//vector multiplication
vect multiply(double k, vect v) {
    vect prod = {k*v.x, k*v.y, k*v.z};
    return prod;
}