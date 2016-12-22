#ifndef _VrmlFunctions_h_
#define _VrmlFunctions_h_
#include <fstream>
using namespace std;
class sphere {
public:
    sphere(double x0,double y0, double z0, double rad):
    x0_(x0), y0_(y0), z0_(z0), rad_(rad) {}
    double x0_, y0_, z0_, rad_;
};

class atom: public sphere {
    public:
        atom(double x0,double y0,double z0,double rad, string nm): sphere(x0,y0,z0,rad), name(nm){}
    private:
        string name;
};


void writeVrmlHeader(ofstream& str);
void writeVrmlSphere(ofstream& str,
                     sphere const& sp, float r, float g, float b, float tranparency);
void writeVrmlIcosahedron(ofstream& ostr, unsigned nIndent);
#endif
