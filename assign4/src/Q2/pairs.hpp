#ifndef PAIRS_H
#define PAIRS_H
#include <iostream>

template <class T1,class T2>
class pairs {
    public:
        pairs(): first_(0),second_(0) {};
        pairs(const T1& a, const T2& b): first_(a),second_(b){};
        pairs(pairs& P) { first_ = P.get_first(); second_ = P.get_second(); };
        ~pairs() {};

        pairs<T1,T2> operator = (pairs<T1,T2> const &P) {
            first_ = P.first_;
            second_ = P.second_;
            return *this;
        }

        T1 get_first(){return first_;};
        T2 get_second(){return second_;};

        void set_first(T1 const& x) { first_ = x;};
        void set_second(T2 const& y) { second_ = y;};

        bool operator == (pairs<T1,T2> &C){
            bool flag = false;
            if (first_ == C.get_first() && second_ == C.get_second())
                flag = true;
            return flag;
        };
        bool operator != (pairs<T1,T2> &C){
            bool flag2 = (*this == C);
            return !flag2;
        }

        inline friend std::ostream& operator << (std::ostream & os,pairs<T1,T2> const & P){
            os << "(" << P.first_ << ',' << P.second_ << ")" << std::endl;
            return os;
        }
        void print() {
            std::cout << "(" << get_first() << ',' << get_second() << ")"<< std::endl;
        }
    private:
        T1 first_;
        T2 second_;
};
#endif
