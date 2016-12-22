#include <iostream>
using namespace std;

int main()
{
    // problem 1
    cout << "*****Beginning of problem 1******\n";
    double x = 0.14580858;
    cout << "x value at default precision :" << x  << endl;
    cout.precision(5);
    cout << "x value at precision 5:" << x  << endl;
    cout.precision(8);
    cout << "x value at precision 8:" <<  x << endl;
    cout.precision(9);
    cout << "x value at precision 9:" <<  x << endl;
    cout << "Therefore, set precision at 8 is enough! "<< endl;
    cout << "*****End of problem 1******\n\n";

    // problem 2
    cout << "*****Beginning of problem 2******\n";
    int neg_i = -72658, pos_i = 72658;
    long neg_l = -75327l, pos_l = 75327l;
    short neg_s = -9, pos_s = 9;
    cout << "Before casting: " << endl;
    cout << "negative int: " << neg_i << ", positive int: " << pos_i << endl;
    cout << "negative long: " << neg_l << ", positive long: " << pos_l << endl;
    cout << "negative short: " << neg_s << ", positive short: " << pos_s << endl;
    // int to unsigned int
    cout << "**************************************"<< endl;
    cout << "After casting: " << endl;
    unsigned int neg_ui = static_cast<unsigned int>(neg_i);
    unsigned int pos_ui = static_cast<unsigned int>(pos_i);
    cout << "postive int -> unsigned int: " << pos_ui << endl;
    cout << "negative int -> unsigned int: " << neg_ui << endl;

    // int to unsigned short
    unsigned short neg_us = static_cast<unsigned short>(neg_i);
    unsigned short pos_us = static_cast<unsigned short>(pos_i);
    cout << "postive int -> unsigned short: " << pos_us << endl;
    cout << "negative int -> unsigned short: " << neg_us << endl;
    // int to unsigned long
    unsigned long neg_ul = static_cast<unsigned long>(neg_i);
    unsigned long pos_ul = static_cast<unsigned long>(pos_i);
    cout << "postive int -> unsigned long: " << pos_ul << endl;
    cout << "negative int -> unsigned long: " << neg_ul << endl;
    cout << "**************************************"<< endl;
    // long to unsigned int
    neg_ui = static_cast<unsigned int>(neg_l);
    pos_ui = static_cast<unsigned int>(pos_l);
    cout << "postive long -> unsigned int: " << pos_ui << endl;
    cout << "negative long -> unsigned int: " << neg_ui << endl;
    // long to unsigned short
    neg_us = static_cast<unsigned short>(neg_l);
    pos_us = static_cast<unsigned short>(pos_l);
    cout << "postive long -> unsigned short: " << pos_us << endl;
    cout << "negative long -> unsigned short: " << neg_us << endl;
    // long to unsigned long
    neg_ul = static_cast<unsigned long>(neg_l);
    pos_ul = static_cast<unsigned long>(pos_l);
    cout << "postive long -> unsigned long: " << pos_ul << endl;
    cout << "negative long -> unsigned long: " << neg_ul << endl;
    cout << "**************************************"<< endl;
    // short to unsigned int
    neg_ui = static_cast<unsigned int>(neg_s);
    pos_ui = static_cast<unsigned int>(pos_s);
    cout << "postive short -> unsigned int: " << pos_ui << endl;
    cout << "negative short -> unsigned int: " << neg_ui << endl;
    // short to unsigned short
    neg_us = static_cast<unsigned short>(neg_s);
    pos_us = static_cast<unsigned short>(pos_s);
    cout << "postive short -> unsigned short: " << pos_us << endl;
    cout << "negative short -> unsigned short: " << neg_us << endl;
    // short to unsigned long
    neg_ul = static_cast<unsigned long>(neg_s);
    pos_ul = static_cast<unsigned long>(pos_s);
    cout << "postive short -> unsigned long: " << pos_ul << endl;
    cout << "negative short -> unsigned long: " << neg_ul << endl;
    cout << "*****End of problem 2******\n\n";

    // problem 4
    cout << "*****Beginning of problem 4******\n";
    float f4 = 1.00000000000000001f, f1 = 1.0001f;
    double d4 = 1.000000000000000011, d1 = 1.0001;
    int i4 = 1;
    cout << "\'f\' means float, \'d\' means double, \'i\' means int " << endl;
    cout << "Inside brakets is the value assigned to the variable" << endl;
    cout << "f1(1.0001f) = " << f1 << " d1(1.0001) = " << d1 << endl;
    cout << "(f1 == d1) = " << (f1 == d1) <<  endl;
    cout << "f4(1.00000000000000001f) " << ' ' << "d4(1.000000000000000011) " ;
    cout << "i4(1) "<< endl;
    if (f4 == i4)
        cout << "(f4 == i4) = " << (f4 == i4)<< endl;
    else
        f4 > i4 ? cout << "f4 is larger." << endl: cout << "i4 is larger." << endl;

    if (f4 == d4)
        cout << "(f4 == d4) = " << (f4 == d4) << endl;
    else
        f4 > d4 ? cout << "f4 is larger." << endl: cout << "d4 is larger." << endl;
    cout << "*****End of problem 4******\n\n";
    return 0;
}
