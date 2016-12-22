#include "VrmlFunctions.h"
#include <fstream>

int main() {
    ofstream ostr("fourSphere.wrl");
    writeVrmlHeader(ostr);
    sphere sa[8] = {
        sphere(0,0,0,1), sphere(0,0,1,1),sphere(0,1,0,1), sphere(0,1,1,1),
        sphere(1,0,0,1), sphere(1,0,1,1),sphere(1,1,0,1), sphere(1,1,1,1)
    };
    for (unsigned i = 0; i < 8; ++i) {
        writeVrmlSphere(ostr, sa[i], 0.0, 1.0, 0.0, 0.0);
        ostr.close();
    }
}
