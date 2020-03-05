#ifndef lrgGradientDescentSolverStrategy_h
#define lrgGradientDescentSolverStrategy_h

#include "lrgLinearModelSolverStrategyI.h"

class GradientSolver:public SolverBase {
public:
	GradientSolver();
	~GradientSolver(){};
	pair<double, double> FitData(vector<pair<double, double> >);
};

#endif