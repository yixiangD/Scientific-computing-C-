#include "VrmlFunctions.h"

using namespace std;
void writeVrmlHeader(ofstream& ostr) {
    ostr << "#VRML V2.0 utf8\n" << endl;
}
void writeVrmlSphere(ofstream& ostr, sphere const& sp,
        float red, float green, float blue, float transparency) {
    ostr
        << "Transform {" << endl
        << " translation " << endl
        << sp.x0_ << ' ' << sp.y0_ << ' ' << sp.z0_ << endl
        << " scale" << endl
        << sp.rad_ << ' ' << sp.rad_ << ' ' << sp.rad_ << endl
        << " children [" << endl
        << " Shape {" << endl
        << " appearance Appearance {" << endl
        << " material Material {" << endl
        << " diffuseColor " << red << ' ' << green << ' ' << blue << endl
        << " transparency " << transparency << endl
        << " }" << endl
        << " }" << endl
        << " geometry Sphere {" << endl
        << "        radius " << sp.rad_ << " } " << endl;
  //  writeVrmlcosahedron(ostr,8);

    ostr
    << " }" << endl
    << " ]" << endl
    << "}" << endl;
}
/*void writeVrmlcosahedron(ofstream& ostr, unsigned nIndent) {
#include "ico12v.txt"// contains information of ICO_LENGTH and char *ico[ICO_LENGTH]
    for (unsigned i = 0; i < ICO_LENGTH; i++) {
        for (unsigned j = 0; j < nIndent; j++) ostr << ' ';
        ostr << ico[i] << endl;
    }
}*/
