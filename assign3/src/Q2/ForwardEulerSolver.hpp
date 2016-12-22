#ifndef FORWARD_EULER_SOLVER_H
#define FORWARD_EULER_SOLVER_H

#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver: public AbstractOdeSolver {
    public:
        ForwardEulerSolver(double (*f)(double,double));
        ~ForwardEulerSolver();

        double SolveEquation();
        double RightHandSide(double y, double t);
    private:
        double (*rhs)(double y,double t);

};

#endif
