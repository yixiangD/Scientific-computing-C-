#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include <iostream>

class Matrix2x2 {
    public:
        Matrix2x2();                                // default constructor
        Matrix2x2(double [4]);                      // array constructor
        Matrix2x2(double,double,double,double);     // element constructor
        Matrix2x2(const Matrix2x2 &obj);            // copy constructor
        ~Matrix2x2();                               // deconstructor

        void Print();
        double Det() const;
        Matrix2x2 Inv();

        // overloading operators
        Matrix2x2 operator - () const;
        Matrix2x2 & operator = (Matrix2x2 const &);
        Matrix2x2 & operator + (Matrix2x2 const &);
        Matrix2x2 & operator - (Matrix2x2 const &);
        Matrix2x2 & operator * (Matrix2x2 const &);
        Matrix2x2 & operator * (double const &);
        double& operator () (const int i,const int j);
        friend std::ostream & operator << (std::ostream &out, const Matrix2x2 &);
        friend Matrix2x2 & operator * (const double &,Matrix2x2 &);

    private:
        double *a11, *a12, *a21, *a22;
};

#endif
