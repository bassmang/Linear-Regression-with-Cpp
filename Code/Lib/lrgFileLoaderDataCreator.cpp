#include "lrgFileLoaderDataCreator.h"
#include<iostream>

// Open file in constructor
FileDataCreator::FileDataCreator(string file_name) {
	infile.open(file_name);
	if(!infile) {
		throw runtime_error("Could not open file");
	}
}

// Ensure file is closed in destructor
FileDataCreator::~FileDataCreator() {
	infile.close();
}

vector<point> FileDataCreator::GetData() {
	vector<point> data_points; // Initialize return vector
	double x, y; // Initialize variables to hold x and y
	// Parse through pairs in file
	while (infile >> x >> y) {
		point p(x, y); // Create point from x and y
    	data_points.push_back(p); // Add point to vector
	}
	infile.close();
	return data_points;
}
