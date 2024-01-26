#include <cmath>
#include <iostream>
#include "sunplot.h"
#define G 6.67430e-11

using namespace std;

//distance to origin or vector length
double vectlen(vect coord) {
    double x = coord.x, y = coord.y, z = coord.z;
    return pow(x*x+y*y+z*z, 0.5);
}

//cartesian to spherical
scoor ctosConv(vect in) {
    scoor out;
    //r = dist to origin
    out.r = vectlen(in);
    
    //phi
    //assume x, y, are all in 1st quad(basic angle), if not convert then later adjust back
    double absx = fabs(in.x), absy = fabs(in.y);
    //prevent div zero
    if(in.x == 0) out.phi = M_PI_2;
    else out.phi = atan(absy/absx);
    if(in.x<0 && in.y>=0) out.phi = M_PI - out.phi; //2nd quad
    if(in.x<0 && in.y<0) out.phi += M_PI; //3rd quad
    if(in.x>=0 && in.y<0) out.phi = 2*M_PI - out.phi; //4th quad

    //delta
    out.delta = acos(in.z/out.r);

    return out;
}

//rotation of vectors
vect vectrot(vect v, vect k, double theta) {
    vect rot;
    rot.x = v.x*cos(theta)+(k.y*v.z-k.z*v.y)*sin(theta)+k.x*(k.x*v.x+k.y*v.y+k.z*v.z)*(1-cos(theta));
    rot.y = v.y*cos(theta)+(-k.x*v.z+k.z*v.x)*sin(theta)+k.y*(k.x*v.x+k.y*v.y+k.z*v.z)*(1-cos(theta));
    rot.z = v.z*cos(theta)+(k.x*v.y-k.y*v.x)*sin(theta)+k.z*(k.x*v.x+k.y*v.y+k.z*v.z)*(1-cos(theta));
    return rot;
}

//simulate earth orbit(sorry celestia)
//sun mass, perihelion, eccentricity, spring equinox angle from perihelion, inclination of earth, mean solar day, earth sidereal day,  
//time increment, output location on celestial sphere, return num of points
int simulate(double m, double p, double e, double alpha, double beta, int solday, int sidday, int dt, int day, vect out[]) {
    int n = 0; //num of data points-1
    int t = 0; //in secs
    double semimaj = p/(1-e); //semimajor axis
    double period = 2*M_PI*pow(semimaj*semimaj*semimaj/(G*m), 0.5);
    //coords, velocity, accel
    vect r, v, a;
    r = {-p, 0, 0}; //initialize
    v = {0, -pow(G*m*(2/vectlen(r)-1/semimaj), 0.5), 0}; //initialize
    a = {(-G*m/pow(vectlen(r), 3))*r.x, (-G*m/pow(vectlen(r), 3))*r.y, 0}; //general formula

    //the fun begins
    for(; t<=period; t+=dt) {
        //update coord for next iter(rprev = r, r = newr(included time))
        vect rprev = r, vprev = v;
        r.x += v.x*dt + 0.5*a.x*dt*dt;
        r.y += v.y*dt + 0.5*a.y*dt*dt;
        v.x += a.x*dt;
        v.y += a.y*dt;
        a = {(-G*m/pow(vectlen(r), 3))*r.x, (-G*m/pow(vectlen(r), 3))*r.y, 0};

        //output coords
        if(t%(day*solday) == 0) {
            vect rot_v, rot_k, earth_rot; //v = sun wrt earth, k = spring equinox rotation axis, earth_rot = earth rotation axis(z-axis)
            rot_v = {-r.x, -r.y, -r.z};
            rot_k = {cos(alpha), sin(alpha), 0};
            earth_rot = {0, 0, 1};
            vect rotated = vectrot(vectrot(rot_v, rot_k, -beta), earth_rot, -t*2*M_PI/(double)sidday);
            double temp_len = vectlen(rotated);
            rotated.x /= temp_len;
            rotated.y /= temp_len;
            rotated.z /= temp_len;
            out[n] = rotated;
            n++;
        }
    }

    return n; //last index
}