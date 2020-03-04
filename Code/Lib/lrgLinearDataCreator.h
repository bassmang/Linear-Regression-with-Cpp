#ifndef lrgLinearDataCreator_h
#define lrgLinearDataCreator_h

#include "lrgDataCreatorI.h"

class DataCreator:public DataCreatorBase {
public:
	double theta0;
	double theta1;
	DataCreator(double theta0, double theta1);
	vector<pair <double, double> > GetData();
};

#endif