#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <complex>
#include <iostream>
using namespace std;

template<class T,unsigned int M=2,unsigned int N=2>
class Matrix {
    public:

        Matrix(){
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    (*this)(i,j) = 0.0;
                }
            }
        };            // default constructor
        Matrix(const T In[M*N]) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    (*this)(i,j) = In[i*N+j];
                }
            }
        };            // array constructor
        Matrix(const Matrix<T,M,N> &obj) {
            for (int i = 0; i < M; i++){
                for (int j = 0; j < N; j++)
                    this->Vec[i*N + j] = obj.Vec[i*N + j];
                   // (*this)(i,j) = obj(i,j);
            }
        };            // copy constructor

        ~Matrix(){};                               // deconstructor

        void Print();/*{
            for (int i = 0; i < M; i++){
                cout << "| " ;
                for (int j = 0; j < N; j++){
                    cout.width(4);
                    cout.precision(4);
                    cout << fixed << scientific << right << *(Vec + i*N + j) << "  " ;
                }
                cout << "|" <<  endl;
            }
        };
*/


// under construction
        T Det() {
            T d = 0.0;
            if (M == N)
                d = det(N,*this);
            else{
                throw length_error("Not square matrix");
            }
            return d;
        }

        T det(const int n, Matrix<T,M,N> & m) {
            T d = 0.0;
            int c,subi,i,j,subj;
            Matrix<T,M,N> submat;
            if (n == 2)
                d = m(0,0) * m(1,1) - m(0,1)*m(1,0);
            else if(n == 1)
                return m(0,0);
            else {
                for (c = 0; c < n; c++){
                    subi = 0;
                    for (i = 1; i < n; i++){
                        subj = 0;
                        for (j = 0; j < n; j++) {
                            if ( j == c) {
                                continue;
                            }
                            submat(subi,subj) = m(i,j);
                            subj++;
                        }
                        subi++;
                    }
                    d = d +(pow(-1,c) * m(0,c) * det(n-1,submat));
                }
            }
            return d;
        };

        Matrix<T,M,N> Inv() {
            Matrix<T,M,N> inv;
            Matrix<T,M-1,N-1> sM;
            T myd, dc;
            double mydd;
            if (M == N) {
                myd = (*this).Det();
                mydd = abs(myd);
                if (mydd == 0.0) {
                    throw range_error("Singular Matrix");
                }
                for(int i = 0;i < M; i++) {
                    for (int j = 0; j < N; j++) {
                        sM = (*this).SubMtr(i,j);
                        dc = pow(-1, i+j) * sM.Det();
                        inv(j,i) = dc/myd;
                    }
                }
            } else {
                throw length_error("Not square matix");
            }
            return inv;
        };

        Matrix<T,M-1,N-1> SubMtr(const int a,const int b) {
            return SubM(*this,a,b);
        }
        Matrix<T,M-1,N-1> SubM(Matrix<T,M,N> &obj,const int a, const int b) {
            Matrix<T,M-1,N-1> m;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (i < a && j < b)
                        m(i,j) = obj(i,j);
                    else if(i > a && j < b)
                        m(i-1,j) = obj(i,j);
                    else if(i < a && j > b)
                        m(i,j-1) = obj(i,j);
                    else if(i > a && j > b)
                        m(i-1,j-1) = obj(i,j);
                }
            }
            return m;
        }

        // overloading operators
        Matrix<T,M,N> & operator = (Matrix<T,M,N> const &obj) {
            for (int i = 0; i < M; i++){
                for (int j = 0; j < N; j++)
                   *(Vec+i*N + j) = obj.Vec[i*N+j];
            }
            return *this;
        };
        T& operator () (const int i,const int j) {
            return this->Vec[i*N + j];
            //return *(Vec+i*N+j);
        };
        const Matrix<T,M,N>  operator + (Matrix<T,M,N> const &obj) {
            Matrix<T,M,N> cp;
            for (int i = 0; i < M; i++){
                for (int j = 0; j < N; j++)
                   cp.Vec[i*N + j] = obj.Vec[i*N+j] + this->Vec[i*N + j];
            }
            return cp;
        };

        /*
       friend Matrix<T,M,N> operator + (Matrix<T,M,N> const &obj1, Matrix<T,M,N> const &obj2) {
            Matrix<T,M,N> obj;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                     obj.Vec[i*M + j] =  obj1.Vec[i*M+j] + obj2.Vec[i*M+j];
            return obj;
        }
        */
        friend Matrix<T,M,N> operator - (Matrix<T,M,N> const &obj1, Matrix<T,M,N> const &obj2) {
            Matrix<T,M,N> obj;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                     obj.Vec[i*N + j] =  obj1.Vec[i*N+j] - obj2.Vec[i*N+j];
            return obj;
        };

        friend Matrix<T,M,N> operator * (Matrix<T,M,N> const &obj1, double const &val) {
            Matrix<T,M,N> obj;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                     obj.Vec[i*N + j] =  obj1.Vec[i*N+j] * val;
            return obj;
        };
        friend Matrix<T,M,N> operator * (double const &val,Matrix<T,M,N> const &obj1) {
            return obj1 * val;
        };

        friend Matrix<T,M,N> operator * (Matrix<T,M,N> &obj1, Matrix<T,M,N> &obj2) {
            Matrix<T,M,N> obj;
            T val,val1,val2;
            if (M == N) {
                for (int k = 0; k < M; k++) {
                    for (int i = 0; i < M; i++){
                        val = 0;
                        for (int j = 0; j < N; j++){
                            val1 = obj1(k,j);
                            val2 = obj2(j,i);
                            val += val1 * val2;
                        }
                        obj(k,i) = val;
                    }
                }
            }
            else {
                throw length_error("Not square matrix!");
            }
            return obj;
        };

        friend Matrix<T,M,N> operator -(Matrix<T,M,N> const &obj) {
            Matrix<T,M,N> nobj;
            for (int i =0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    nobj.Vec[i*N + j] = -obj.Vec[i*N + j];
                }
            }
            return nobj;
        };
        friend ostream & operator << (ostream &out, const Matrix<T,M,N> &obj) {
            if (typeid(obj.Vec[0]) == typeid(complex<double>)){
                for (int i = 0; i < M; i++){
                    out << "| " ;
                    for (int j = 0; j < N; j++){
                        out.width(8);
                        out.fill(' ');
                        out.precision(4);
                        complex <double> data = obj.Vec[i];
                        double re = data.real(), im = data.imag();
                        if (im > 0)
                            out << right << re << " + "<< im  << 'i';
                        else
                            out << right << re << " - "<< abs(im)  << 'i';
                        if( j < N-1 )
                            out << "  " ;
                        else
                            out << ' ';
                    }
                    out << "|" <<  endl;
                }
            }else {
                for (int i = 0; i < M; i++){
                    cout << "| " ;
                    for (int j = 0; j < N; j++){
                        out.width(4);
                        out.precision(3);
                        out << fixed << scientific <<  right << obj.Vec[i*N + j];
                        if( j < N-1 )
                            out << "  " ;
                        else
                            out << ' ';
                    }
                    out << "|" <<  endl;
                }
            }
            return out;
        };

    private:
        T Vec[M*N];
};

/*template <>
std::ostream & operator << <complex<double>, unsigned int M, unsigned int N>(ostream &out, const Matrix<complex<double>, M, N> &obj) {
    for (int i = 0; i < M; i++){
        out << "| " ;
        for (int j = 0; j < N; j++){
            out.width(4);
            out.precision(4);
            out << fixed << scientific << right << (obj(i,j)).real() << " + " << (obj(i,j)).imag()  << "i ";
        }
        out << "|" <<  endl;
    }
    return out;
};*/

template< class T, unsigned int M, unsigned int N >
void Matrix< T, M, N >::Print() {
    if (typeid(Vec[0]) == typeid(complex<double>)){
        for (int i = 0; i < M; i++){
            cout << "| " ;
            for (int j = 0; j < N; j++){
                cout.width(8);
                cout.fill(' ');
                cout.precision(4);
                complex <double> data = Vec[i];
                double re = data.real(), im = data.imag();
                if (im > 0)
                    cout << right << re << " + "<< im  << 'i';
                else
                    cout << right << re << " - "<< abs(im)  << 'i';
                if( j < N-1 )
                    cout << "  " ;
                else
                    cout << ' ';
            }
            cout << "|" <<  endl;
        }
    }else {
        for (int i = 0; i < M; i++){
            cout << "| " ;
            for (int j = 0; j < N; j++){
                cout.width(4);
                cout.precision(3);
                cout << fixed << scientific <<  right << *(Vec + i*N + j);
                if( j < N-1 )
                    cout << "  " ;
                else
                    cout << ' ';
            }
            cout << "|" <<  endl;
        }
    }
};

#endif

