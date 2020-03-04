#ifndef lrgDataCreatorI_h
#define lrgDataCreatorI_h

#include<vector>
using namespace std;

class DataCreatorBase {
	public:
		virtual vector<pair <double, double> > GetData() = 0;
};

#endif