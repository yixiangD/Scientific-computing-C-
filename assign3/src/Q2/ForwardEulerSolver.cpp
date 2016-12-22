#include <iostream>
#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"

ForwardEulerSolver::ForwardEulerSolver(double (*f)(double y, double t)) {
    rhs = f;
}
double ForwardEulerSolver::SolveEquation() {
    double *yold = new double(initialValue), *told = new double(initialTime);
    double h = stepSize;
    double ynew, *tend = new double (finalTime);
    while(*told < (*tend) - 1e-2) {
       std::cout << 'y' << '[' << *told << "] = " << *yold << std::endl;
       ynew = *yold + h * RightHandSide(*yold,*told);
       *yold = ynew;
       *told = *told + h;
    }
    delete yold;
    delete told;
    delete tend;
    return ynew;
}

double ForwardEulerSolver::RightHandSide(double y,double t) {
    return rhs(y,t);
}

ForwardEulerSolver::~ForwardEulerSolver() {}
