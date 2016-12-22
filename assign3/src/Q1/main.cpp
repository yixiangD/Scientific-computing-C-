#include <iostream>
#include <math.h>
#include "Matrix2x2.hpp"
using namespace std;
int main(int argc, char* argv[]){
// create separator string
    string sep(30, '=');
    sep = '\n' + sep + '\n';
    cout << sep << "default constuctor" << sep << endl;
    Matrix2x2 A(1,2,3,4);
    cout << "A() => " << endl;
    A.Print();
    cout << sep << "copy constructor" << sep << endl;
    Matrix2x2 B = A;
    cout << "B = A => " << endl;
    B.Print();
    cout << sep << "assignment constructor" << sep << endl;
    double data[4] = {4.0, 3.5, 2.0, 2.0};
    Matrix2x2 C(data);
    cout << "C({a1,a2,a3,a4}) => " << endl;
    C.Print();
    cout << sep << "determinant method" << sep << endl;
    double d = C.Det();
    cout << "d = C.Det() => " << d << endl;
    cout << sep << "inverse method" << sep << endl;
    cout << "E = C => " << endl;
    Matrix2x2 E = C.Inv();
    cout << "E = E.Inv() => " << endl;
    E.Print();
    cout << sep << "matrix assignment (operator=)" << sep << endl;
    Matrix2x2 F;
    F = E;
    cout << "F = E => " << endl;
    F.Print();
    cout << sep << "overloaded unary subtraction (operator-)" << sep << endl;
    Matrix2x2 G;
    G = -F;
    cout << "G = -F => " << endl;
    G.Print();
    cout << sep << "overloaded binary addition/subtraction (operator+/-)" << sep << endl;
    cout << "C => " << endl;
    C.Print();
    cout << "F => " << endl;
    F.Print();
    Matrix2x2 H1, H2;
    H1 = C + F;
    cout << "H1 = C + F =>" << endl;
    H1.Print();
    H2 = C - F;
    cout << "H2 = C - F =>" << endl;
    H2.Print();
    cout << sep << "scalar multiplication method" << sep << endl;
    Matrix2x2 I = H2 * M_PI;
    cout << "I = H2 * PI =>" << endl;

    I.Print();
    cout << sep << "matrix multiplication method" << sep << endl;
    cout << "H1 =>" << endl;
    H1.Print();
    cout << "H2 =>" << endl;
    H2.Print();
    Matrix2x2 J = H1 * H2;
    cout << "J = H1 * H2 =>" << endl;
    J.Print();
    cout << sep << "ostream (operator<<)" << sep << endl;
    cout << "cout << J << endl;" << endl;
    cout << J << endl;
    //Done with testing; Exit and call destructors
//    A.Print();
//    cout << A(0,0) << endl;
    return 0;
}
