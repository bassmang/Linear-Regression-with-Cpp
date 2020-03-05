#include "lrgFileLoaderDataCreator.h"
#include <fstream>

FileDataCreator::FileDataCreator(string fn) {
	file_name = fn;
}

vector<point> FileDataCreator::GetData() {
	ifstream infile(file_name); // Open stream to file
	vector<point> data_points; // Initialize return vector
	double x, y; // Initialize variables to hold x and y
	// Parse through pairs in file
	while (infile >> x >> y) {
		point p(x, y); // Create point from x and y
    	data_points.push_back(p); // Add point to vector
	}
	return data_points;
}
