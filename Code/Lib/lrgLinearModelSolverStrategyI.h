#ifndef lrgLinearModelSolverStrategyI_h
#define lrgLinearModelSolverStrategyI_h
#include<vector>
using namespace std;
typedef pair<double, double> point;

class SolverBase {
	public:
		virtual point FitData(vector<point>) = 0;
};

#endif