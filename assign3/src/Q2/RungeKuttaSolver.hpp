#ifndef RUNGE_KUTTA_SOLVER_H
#define RUNGE_KUTTA_SOLVER_H

#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver: public AbstractOdeSolver {
    public:
        RungeKuttaSolver(double (*fun) (double,double));
        ~RungeKuttaSolver();

        double SolveEquation();
        double RightHandSide(double y,double t);
    private:
        double (*rhs)(double,double);
};

#endif
