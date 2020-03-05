#ifndef lrgDataCreatorI_h
#define lrgDataCreatorI_h
#include<vector>

using namespace std;

typedef pair<double, double> point;

class DataCreatorBase {
	public:
		virtual vector<point> GetData() = 0;
};

#endif