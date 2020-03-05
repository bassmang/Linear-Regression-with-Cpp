#include "lrgGradientDescentSolverStrategy.h"
#include<iostream>
#include "../3rdParty/Eigen-3.2.2.1/Eigen/Dense"

using namespace Eigen;

GradientSolver::GradientSolver(int iters, double lr, double t0_guess, double t1_guess) {
	epochs = iters;
	alpha = lr;
	theta0_init = t0_guess;
	theta1_init = t1_guess;
}

pair<double, double> GradientSolver::FitData(const vector<pair<double, double> > points) {

	return pair <double,double>(1, 1);;
}