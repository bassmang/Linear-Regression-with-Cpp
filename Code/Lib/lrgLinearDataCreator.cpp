#include "lrgLinearDataCreator.h"
#include<iostream>
#include<random>

DataCreator::DataCreator(double t0, double t1) {
	theta0 = t0;
	theta1 = t1;
}

vector<pair <double, double> > DataCreator::GetData() {
	// Set up random generator with x distribution from 0 to 0
	// and the noise distribution from -1 to 1.
	std::default_random_engine generator;
	std::uniform_real_distribution<double> x_dist(0,10);
	std::uniform_real_distribution<double> noise_dist(-1,1);
	int n_points = 100; // Set number of generated points
	vector<pair <double, double> > data_points; // Initialize return vector
	// Loop through and generate a new x and noise point. Use these
	// to calculate y, along with theta1 and theta0. Append the results
	// the the result vector.
	for(int i = 0; i < n_points; i++) {
		double x = x_dist(generator);
		double noise = noise_dist(generator);
		double y = theta1*x + theta0 + noise;
		pair <double,double> p(x, y);
		data_points.push_back(p);
	}
	return data_points; 
}
