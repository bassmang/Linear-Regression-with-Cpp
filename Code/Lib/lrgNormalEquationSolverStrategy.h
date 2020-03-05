#ifndef lrgNormalEquationSolverStrategy_h
#define lrgNormalEquationSolverStrategy_h

#include "lrgLinearModelSolverStrategyI.h"

class Solver:public SolverBase {
public:
	Solver();
	~Solver(){};
	pair<double, double> FitData(vector<pair<double, double> >);
};

#endif