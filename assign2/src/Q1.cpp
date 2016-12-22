#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

double f(double x)
{
    return exp(x) + pow(x,3) - 5;
}

double df(double x)
{
    return exp(x) + 3*pow(x,2);
}

int main()
{
    double x0 = 1.0;
    double xnew;
    double valf, valdf, eps = 1.0;
    double e = 0.1;
    do {
        valf = f(x0);
        valdf = df(x0);
        xnew = x0 - valf/valdf;
        eps = abs(xnew - x0);
        x0 = xnew;
    }while (eps > e);
  /*  cout << "****************Q1*******************************" << endl;
    cout << "*************************************************" << endl;
    cout << "Given f(x) = exp(x) + x^3 - 5" << endl;
    cout << "The solution to f(x) = 0 is x = ";*/
    cout << x0 << endl;
}