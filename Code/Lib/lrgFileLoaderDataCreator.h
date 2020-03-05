#ifndef lrgFileLoaderDataCreator_h
#define lrgFileLoaderDataCreator_h
#include <string>
#include <fstream>
#include "lrgDataCreatorI.h"

class FileDataCreator:public DataCreatorBase {
private:
	ifstream infile;
public:
	FileDataCreator(string file_name);
	~FileDataCreator();
	vector<point> GetData();
};

#endif