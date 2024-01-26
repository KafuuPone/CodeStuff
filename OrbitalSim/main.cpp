#include <iostream>
#include <cstdlib>
#include "classes.h"
#include "func.h"
#include "output.h"

using namespace std;

int main() {
    int n = 3; //Number of bodies
    body* bodies = (body*)malloc(n*sizeof(body)); //array of bodies, n elements

    //set parameters of bodies
    body sun, earth, moon;
    //parameter m
    sun.m = 1.989e30;
    earth.m = 5.972e24;
    moon.m = 7.342e22;
    //lagr.m = 100;
    //parameter r
    sun.r = {0, 0, 0};
    earth.r = {-1.496e11, 0, 0};
    moon.r = {-3.844e8-1.496e11, 0, 0};
    //lagr.r = {-1.471e11*1.010122, 0, 0};
    //parameter v
    sun.v = {0, 0, 0};
    earth.v = {0, -29.78e3, 0};
    moon.v = {0, -1.022e3-29.78e3, 0};
    // lagr.v = {0, -3.029e4*1.010122, 0};
    //save into bodies array
    bodies[0] = sun;
    bodies[1] = earth;
    bodies[2] = moon;
    //bodies[2] = lagr;
    //parameter a
    a_update(bodies, n);

    //time related parameters
    int t = 0; //number of time increments(default unit: seconds)
    int period = 365*24*60*60; //period of simulation(number of t's)
    int interval = 12*60*60; //data retrieval interval

    //simulation start
    FILE** files = filearr(n); //open file
    for(; t<period; t++) {
        bodies_update(bodies, n);
        //do stuff
        if(t%interval == 0)
            retrievedata(files, bodies, n);
    }
    closefiles(files, n);

    //Let's hope we get here
    cout << "Simulation Success";

    return 0;
}