#ifndef lrgLinearDataCreator_h
#define lrgLinearDataCreator_h

#include "lrgDataCreatorI.h"

class DataCreator:public DataCreatorBase {
public:
	double theta0;
	double theta1;
	int n_points;
	DataCreator(double theta0, double theta1, int n_points);
	vector<pair <double, double> > GetData();
};

#endif