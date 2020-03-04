#ifndef lrgLinearDataCreator_h
#define lrgLinearDataCreator_h

#include "lrgDataCreatorI.h"

class DataCreator:public DataCreatorBase {
public:
	DataCreator();
	vector<pair <double, double> > GetData();
};

#endif