#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double epsofv(double v) {
    int vpow = ilogb(v) - 52;
    double eps = ldexp(1.0, vpow);
    return eps;
}
int main()
{
    // problem 5 & problem 6
    cout << "***********Beginning of problem 5 & 6***********\n";
    long double a = 1 - 0.2 - 0.2 - 0.2 - 0.2 - 0.2, b = 0.0;
    cout << "a = 1 - 0.2 - 0.2 - 0.2 - 0.2 -0.2 = " << a << ", b = " << b << endl;
    cout << "(a == b) = " << (a == b) << endl;
    double v = abs(a - b);
    double eps;
    eps = epsofv(v);
//    cout << "v = abs(a - b) = " << v ;
//    cout << ", esp = " << eps << endl;
    double v1 = 0.2;
    double eps1 = epsofv(v1);
    cout << "v1 = " << v1 << ", eps1 = " << eps1 << endl;
    double v2 = 1.0;
    double eps2 = epsofv(v2);
    cout << "v2 = " << v2 << ' ' << "eps2 = " << eps2 << endl;
    cout << "********End of problem 5 & 6***********\n\n";
    // problem 7
    cout << "********Beginning of problem 7******** \n" ;
    double y = 1.0, zero1 = 1e-156, zero2 = 1e-300, inf1, inf2;
    double yneg = -1.0, inf3 = yneg/(zero1*zero1);
    inf1 = y/(zero1*zero1);
    inf2 = log(zero2*zero2);

    cout << "inf1 = 1.0/(1e-156*1e-156) = " << inf1 << endl;
    cout << "inf2 = log(1e-300*1e-300) = " << inf2 << endl;
    cout << "inf3 = -1.0/(1e-156*1e-156) = " << inf3 << endl;
    cout << "inf3 == inf2: " << (inf3 == inf2) << endl;
    cout << "inf1 == inf2: " << (inf1 == inf2) << endl;
    double nan1, nan2;
    nan1 = 0.0 * inf1;
    nan2 = 0.0 * inf2;
    cout << "nan1 = 0.0 * inf1 = " << nan1 << endl;
    cout << "nan2 = 0.0 * inf2 = " << nan2 << endl;
    cout << "nan1 == nan2: " << (nan1 == nan2) << endl;
    cout << "********End of problem 7***********\n\n";
    return 0;
}
