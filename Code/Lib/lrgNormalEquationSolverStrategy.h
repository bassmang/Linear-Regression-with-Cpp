#ifndef lrgNormalEquationSolverStrategy_h
#define lrgNormalEquationSolverStrategy_h

#include "lrgLinearModelSolverStrategyI.h"

class NormalSolver:public SolverBase {
public:
	NormalSolver();
	~NormalSolver(){};
	pair<double, double> FitData(vector<pair<double, double> >);
};

#endif