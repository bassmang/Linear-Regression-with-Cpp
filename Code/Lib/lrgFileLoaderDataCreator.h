#ifndef lrgFileLoaderDataCreator_h
#define lrgFileLoaderDataCreator_h
#include <string>
#include "lrgDataCreatorI.h"

class FileDataCreator:public DataCreatorBase {
private:
	string file_name;
public:
	FileDataCreator(string file_name);
	~FileDataCreator(){};
	vector<point> GetData();
};

#endif