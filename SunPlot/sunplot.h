//cartesian coordinates/vector form
class vect {
    public:
        double x, y, z;
};

//spherical coordinates
class scoor {
    public:
        double r, delta, phi;
};

//distance to origin or vector length
double vectlen(vect coord);

//cartesian to spherical
scoor ctosConv(vect in);

//rotation of vectors
vect vectrot(vect v, vect k, double theta);

//simulate earth orbit(sorry celestia)
//sun mass, perihelion, eccentricity, spring equinox angle from perihelion, inclination of earth, mean solar day, earth sidereal day,  
//time increment, plot repetition
//output delta and phi, return num of points
int simulate(double m, double p, double e, double alpha, double beta, int solday, int sidday, int dt, int day, vect out[]);