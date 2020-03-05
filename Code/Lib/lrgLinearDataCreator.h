#ifndef lrgLinearDataCreator_h
#define lrgLinearDataCreator_h

#include "lrgDataCreatorI.h"

class DataCreator:public DataCreatorBase {
private:
	double theta0;
	double theta1;
	int n_points;
public:
	DataCreator(double theta0, double theta1, int n_points);
	~DataCreator();
	vector<point> GetData();
};

#endif