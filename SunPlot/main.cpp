#include <iostream>
#include "sunplot.h"

int main() {
    //sun mass, perihelion, eccentricity, spring equinox angle from perihelion, inclination of earth, mean solar day, earth sidereal day, 
    //time increment, plot repetition
    //earth: simulate(1.98847e30, 147100632000, 0.01671, 1.307384, 0.409045, 60)
    vect globe[5000]; //3d
    int n = simulate(1.98847e30, 1.47100632e11, 0.01671, 1.307384, 0.409045, 86400, 86164, 1, 10, globe);

    FILE* f;
    f = fopen("output.csv", "w");
    for(int i=0; i<n; i++) {
            vect sun = globe[i];
            if (f != NULL)
                fprintf(f, "%lf, %lf, %lf\n", sun.x, sun.y, sun.z);
        }
    fclose(f);

    std::cout << "Success";

    return 0;
}