#include <iostream>
#include "ForwardEulerSolver.hpp"
#include "RungeKuttaSolver.hpp"
using namespace std;

double RHS(double y,double t) {
    double dydt = 1 + t;
    return dydt;
}

int main() {
    double t0 = 0.0;
    double t1 = 1.0;
    double y0 = 2;
    double step = 0.05;
    double res1,res2,ana;
    ForwardEulerSolver * p_ode1 = new ForwardEulerSolver(RHS);
    p_ode1 -> SetStepSize(step);
    p_ode1 -> SetTimeInterval(t0,t1);
    p_ode1 -> SetInitialValue(y0);
//    res1 = p_ode1 -> SolveEquation();
 //   cout << "Forward Euler Solver solution = " << res1 << endl;
    delete p_ode1;
    RungeKuttaSolver * p_ode2 = new RungeKuttaSolver(RHS);
    p_ode2 -> SetStepSize(step);
    p_ode2 -> SetTimeInterval(t0,t1);
    p_ode2 -> SetInitialValue(y0);
    res2 = p_ode2 -> SolveEquation();
    cout << "Runge-Kutta Solver solution = " << res2 << endl;
    ana = (t1*t1 + 2*t1 + 4) / 2;
    cout << "Analytic solution = " << ana << endl;
    return 0;
}
