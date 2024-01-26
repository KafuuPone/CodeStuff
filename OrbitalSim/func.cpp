#include <cmath>
#include "classes.h"
#include "vect.h"

#include "func.h"

//constants
#define G 6.67430e-11
#define DT 1 //time increment

//generate gfield experienced celestial body of index n (gfield = a)
//ensure n < tot, bodies[] = array of all bodies
vect gfield(const body* bodies, int n, int tot) {
    vect field = {0, 0, 0};
    body target = bodies[n]; //target_r = coords of body to calculate
    for(int i=0; i < tot; i++) {
        if(i == n) continue; //skip target body
        body body_i = bodies[i]; //temp body
        vect r_i = subtract(target.r, body_i.r); //relative position with temp body
        //increment gfield
        field = add(field, multiply(body_i.m/pow(vectlen(r_i), 3), r_i));
    }
    field = multiply(-G, field); //gfield = -G*sum(m_i*r_i/|r_i|^3)
    return field;
}

//updates r for each body from their current a and v
void r_update(body* bodies, int tot) {
    for(int i=0; i<tot; i++) {
        body* body_ptr = bodies+i;
        //r = r0 + vt + .5at^2
        (*body_ptr).r = add((*body_ptr).r, add(multiply(DT, (*body_ptr).v), multiply(.5*DT*DT, (*body_ptr).a)));
    }
}

//updates acceleration of each body from their current r
void a_update(body* bodies, int tot) {
    for(int i=0; i<tot; i++) {
        body* body_ptr = bodies+i;
        //update gfield, aka accel
        (*body_ptr).a = gfield(bodies, i, tot);
    }
}

//updates velocity of each body from their current a
void v_update(body* bodies, int tot) {
    for(int i=0; i<tot; i++) {
        body* body_ptr = bodies+i;
        //update velocity, v = v0+at
        (*body_ptr).v = add((*body_ptr).v, multiply(DT, (*body_ptr).a));
    }
}

//updates the position and etc of all bodies in a single DT, assuming constant a during whole interval
void bodies_update(body* bodies, int tot) {
    //order MATTERS
    r_update(bodies, tot);
    v_update(bodies, tot);
    a_update(bodies, tot);
    //true part of all data
}