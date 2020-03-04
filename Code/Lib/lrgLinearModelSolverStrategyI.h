#ifndef lrgLinearModelSolverStrategyI_h
#define lrgLinearModelSolverStrategyI_h

#include<vector>
using namespace std;

class SolverBase {
	public:
		virtual pair<double, double> FitData(vector<pair<double, double> >) = 0;
};

#endif