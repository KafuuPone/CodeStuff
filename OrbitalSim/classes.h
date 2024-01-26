//vector
class vect {
    public:
        double x, y, z;
};

//celestial body
class body {
    public:
        vect r, v, a; //position, velocity, accel
        double m; //mass
};