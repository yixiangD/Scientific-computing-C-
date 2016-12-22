#ifndef ABSTRACTODESOLVER_HPP
#define ABSTRACTODESOLVER_HPP

class AbstractOdeSolver {
    protected:
        double stepSize;
        double initialTime;
        double finalTime;
        double initialValue;

    public:
        AbstractOdeSolver(){};
        ~AbstractOdeSolver(){};

        void SetStepSize(double h) {stepSize = h;};
        void SetTimeInterval(double t0, double t1) {
            initialTime = t0;
            finalTime = t1;
        };
        void SetInitialValue(double y0) {initialValue = y0;};
        virtual double SolveEquation() = 0;
        virtual double RightHandSide(double y, double t) = 0;
};

#endif //ABSTRACTODESOLVER_HPP
