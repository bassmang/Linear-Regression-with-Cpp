#ifndef lrgNormalEquationSolverStrategy_h
#define lrgNormalEquationSolverStrategy_h

#include "lrgLinearModelSolverStrategyI.h"

class NormalSolver:public SolverBase {
public:
	NormalSolver();
	~NormalSolver(){};
	point FitData(vector<point>);
};

#endif