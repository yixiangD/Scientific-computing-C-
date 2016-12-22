#include "Matrix2x2.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

// constructors
Matrix2x2::Matrix2x2() {
    a11 = new double(0.0); a12 = new double(0.0);
    a21 = new double(0.0); a22 = new double(0.0);
}

Matrix2x2::Matrix2x2(double a1,double a2,double a3,double a4) {
    a11 = new double(a1); a12 = new double(a2);
    a21 = new double(a3); a22 = new double(a4);
}

Matrix2x2::Matrix2x2(double init[4]) {
    a11 = new double(init[0]); a12 = new double(init[1]);
    a21 = new double(init[2]); a22 = new double(init[3]);
}

Matrix2x2::Matrix2x2(Matrix2x2 const &A) {
    cout << "Copy constructor called... " << endl;
    a11 = new double(*(A.a11));
    a12 = new double(*(A.a12));
    a21 = new double(*(A.a21));
    a22 = new double(*(A.a22));
}


Matrix2x2::~Matrix2x2() {
    cout << "Destructor called! " << endl;
    delete a11;
    delete a12;
    delete a21;
    delete a22;
}

void Matrix2x2::Print() {
    cout << scientific;
    cout << setprecision(3);
    cout << "| " << *a11 << '\t' << *a12 << " |" << endl;
    cout << "| " << *a21 << '\t' << *a22 << " |" << endl;
}

double Matrix2x2::Det() const {
    return (*a11) * (*a22) - (*a21) * (*a12);
}

Matrix2x2 Matrix2x2::Inv() {
    double inv11 = 0.0,inv12 = 0.0,inv21 = 0.0,inv22 = 0.0;
    double determinant = this->Det();
    try {
        if (determinant == 0)
            throw "Matrix not invertable!";
    }catch (const char* msg) {
        cerr << msg << endl;
    }
    /*if (determinant == 0)
        throw "Matrix not invertable!";
    else {
        inv11 = (*a22) / determinant, inv12 = -(*a12) / determinant;
        inv21 = -(*a21) / determinant, inv22 = (*a11) / determinant;
    }*/
    Matrix2x2 Ainv(inv11,inv12,inv21,inv22);
    return Ainv;
}

// operators overload
Matrix2x2 Matrix2x2::operator - () const {
    Matrix2x2 negA(-(*a11),-(*a12),-(*a21),-(*a22));;
    return negA;
}

Matrix2x2& Matrix2x2::operator = (Matrix2x2 const &A) {
    a11 = new double(*(A.a11)); a12 = new double(*(A.a12));
    a21 = new double(*(A.a21)); a22 = new double(*(A.a22));
    return *this;
}

Matrix2x2& Matrix2x2::operator + (Matrix2x2 const &A) {
    *a11 = *a11 + *(A.a11); *a12 = *a12 + *(A.a12);
    *a21 = *a21 + *(A.a21); *a22 = *a22 + *(A.a22);
    return *this;
}

Matrix2x2& Matrix2x2::operator - (Matrix2x2 const &A) {
    *a11 = *a11 - *(A.a11); *a12 = *a12 - *(A.a12);
    *a21 = *a21 - *(A.a21); *a22 = *a22 - *(A.a22);
    return *this;
}

Matrix2x2& Matrix2x2::operator * (Matrix2x2 const &A) {
    *a11 = (*a11) * (*(A.a11)); *a12 = (*a12) * (*(A.a12));
    *a21 = (*a21) * (*(A.a21)); *a22 = (*a22) * (*(A.a22));
    return *this;
}

Matrix2x2& Matrix2x2::operator * (double const &s) {
    *a11 = s * (*a11); *a12 = s * (*a12);
    *a21 = s * (*a21); *a22 = s * (*a22);
    return *this;
}
ostream& operator <<(ostream &out, const Matrix2x2 &A) {
    out << "| " << *(A.a11) << "  " << *(A.a12) << " |" << endl;
    out << "| " << *(A.a21) << "  " << *(A.a22) << " |" ;
    return out;
}

Matrix2x2 & operator *( const double &t,Matrix2x2 & A ){
    return A * t;
}

double& Matrix2x2::operator () (const int i,const int j) {
    if (i == 0) {
        if (j == 0)
            return *a11;
        else
            return *a12;
    }
    else {
        if (j == 0)
            return *a21;
        else
            return *a22;
    }
}
