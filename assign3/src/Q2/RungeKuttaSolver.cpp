#include "RungeKuttaSolver.hpp"
#include <iostream>

RungeKuttaSolver::RungeKuttaSolver(double (*f)(double y,double t)) {
    rhs = f;
}

double RungeKuttaSolver::RightHandSide(double y, double t) {
    return rhs(y,t);
}

double RungeKuttaSolver::SolveEquation() {
    double *yold = new double(initialValue), *told = new double(initialTime);
    double *tend = new double(finalTime);
    double ynew, k1, k2, k3, k4, h = stepSize, thalf;
    while(*told < (*tend)){
        k1 = h * RightHandSide(*yold,*told);
        thalf = *told + 0.5*h;
        k2 = h * RightHandSide(*yold + 0.5*k1,thalf);
        k3 = h * RightHandSide(*yold + 0.5*k2,thalf);
        k4 = h * RightHandSide(*yold + k3,*told + h);
        std::cout << 'y' << '[' << *told << "] = " << *yold << std::endl;
        ynew = *yold + (k1 + 2*k2 + 2*k3 + k4) / 6;
        *yold = ynew;
        *told = *told + h;
    }
    delete yold;
    delete told;
    delete tend;
    return ynew;
}

RungeKuttaSolver::~RungeKuttaSolver() {}
