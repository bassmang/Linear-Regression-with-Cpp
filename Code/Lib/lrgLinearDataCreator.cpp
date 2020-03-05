#include "lrgLinearDataCreator.h"
#include<random>

DataCreator::DataCreator(double t0, double t1, int n) {
	theta0 = t0;
	theta1 = t1;
	n_points = n;
}

DataCreator::~DataCreator() { }

vector<point> DataCreator::GetData() {
	// Set up random generator with x distribution from 0 to 0
	// and the noise distribution from -1 to 1.
	default_random_engine generator;
	uniform_real_distribution<double> x_dist(0,10);
	uniform_real_distribution<double> noise_dist(-1,1);
	vector<point> data_points; // Initialize return vector
	// Loop through and generate a new x and noise point. Use these
	// to calculate y, along with theta1 and theta0. Append the results
	// the the result vector.
	for(int i = 0; i < n_points; i++) {
		double x = x_dist(generator);
		double noise = noise_dist(generator);
		double y = theta1*x + theta0 + noise;
		point p(x, y);
		data_points.push_back(p);
	}
	return data_points; 
}