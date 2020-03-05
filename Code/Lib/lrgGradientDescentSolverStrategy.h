#ifndef lrgGradientDescentSolverStrategy_h
#define lrgGradientDescentSolverStrategy_h

#include "lrgLinearModelSolverStrategyI.h"

class GradientSolver:public SolverBase {
private:
	int epochs; // Number of iterations
	double alpha; // Learning rate
	double theta0_init; // Initial guess of theta0
	double theta1_init; // Initial guess of theta1
public:
	GradientSolver(int epochs, double alpha, double theta0_init, double theta1_init);
	~GradientSolver(){};
	point FitData(vector<point>);
};

#endif