#include <stdio.h>
#include <math.h>

//cartesian coordinates/vector form
struct vect {
    double x, y, z;
};

struct vect vectrot(struct vect v, struct vect k, double theta) {
    struct vect rot;
    theta = -theta;
    rot.x = v.x*cos(theta)+(k.y*v.z-k.z*v.y)*sin(theta)+k.x*(k.x*v.x+k.y*v.y+k.z*v.z)*(1-cos(theta));
    rot.y = v.y*cos(theta)+(-k.x*v.z+k.z*v.x)*sin(theta)+k.y*(k.x*v.x+k.y*v.y+k.z*v.z)*(1-cos(theta));
    rot.z = v.z*cos(theta)+(k.x*v.y-k.y*v.x)*sin(theta)+k.z*(k.x*v.x+k.y*v.y+k.z*v.z)*(1-cos(theta));
    return rot;
}

int main() {
    struct vect rot, v = {1, 2, 3}, k = {sin(1), cos(1), 0};
    rot = vectrot(v, k, 0.7);
    printf("%lf %lf %lf", rot.x, rot.y, rot.z);
}