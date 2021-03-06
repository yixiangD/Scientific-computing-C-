#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "gnuplot-iostream.h"
//#include "gnuplot.h"

/******************************************
 *
 *the commented blocks are used to impose
 * periodic bc's, not tested yet.
 *
 * current bc's is 0 at four laterals of
 * the square domain
 *
 * ***************************************/

// function used to calculate RHS of the eq.
double fun(double x, double y) {
    double val;
    val = sin(M_PI*x) * sin(M_PI*y);
    return val;
}

int main(int argc, char* argv[]) {
    //nr is # of row, nc # of column, chose to be the same for convenience.
    int nr = 51;
    int nc, ncores;
    std::fstream out;
    out.open("out.txt");
    ncores = atoi(argv[2]);
    nr = atoi(argv[1]);
    nc = nr;

    std::vector< std::vector<double> > uold, unew, fout;
    uold.resize(nr, std::vector<double>(nc,0.0));
    unew.resize(nr, std::vector<double>(nc,0.0));
    fout.resize(nr, std::vector<double>(nc,0.0));
    double dx = 2.0/static_cast<double>(nc - 1);
    double xval, yval;
    for (int i = 0; i < nc; i++){
        for (int j = 0; j < nr; j++) {
            xval = dx * i - 1.0;
            yval = dx * j - 1.0;
            //xcor[i][j] = xval;
            //ycor[i][j] = yval;
            fout[i][j] = fun(xval, yval);
        }
    }

    int Mloop = 1e4, count = 0;
    double error = 1e-5, sum = 1.0;
    while (sqrt(sum) > error && count < Mloop){
        sum = 0.0;
        count += 1;
        for (int i = 1; i < nc - 1; i++) {
            for (int j = 1; j < nr - 1; j++) {
                unew[i][j] = (uold[i+1][j] + uold[i-1][j] + uold[i][j-1] + uold[i][j+1]) - dx*dx*fout[i][j];
                unew[i][j] /= (4 + dx*dx);
                sum += pow((unew[i][j] - uold[i][j]),2);
                uold[i][j] = unew[i][j];
            }
        }
    }
    Gnuplot gp;
    gp << "set terminal png\n";
//    gp << "set dgrid3d\n";
    gp << "set pm3d\n";
    gp << "set contour\n";
    gp << "set output 'mygraph.png'\n";
    gp << "splot '-' matrix with lines\n";
    gp.send(unew);

    for (int i = 0; i< nr; i++) {
        for (int j = 0; j < nc; j++) {
            out << unew[i][j] << ' ';
        }
        out << '\n';
    }
    out.close();
    std::cout << "iteration: " << count << " Error: " << sqrt(sum) << std::endl;
    return 0;
}
