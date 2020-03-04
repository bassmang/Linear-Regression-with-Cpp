#include "catch.hpp"
#include "lrgLinearDataCreator.h"
#include "lrgNormalEquationSolverStrategy.h"
#include <iostream>
#include <vector>
#include <cmath>

TEST_CASE( "Test instantiating an instance of data generation" ) {
	DataCreator d(1, 1, 1); // Test simple instantiation
	d.GetData(); // Test function works
	REQUIRE( 1 == 1 ); // Make naive assertion
}

TEST_CASE( "Test number and distribution from GetData function" ) {
	// Set random values for theta0, theta1, and number of points
	double theta0 = 50.0;
	double theta1 = 0.5;
	double n_points = 1000000;
	// Generate data
	DataCreator d(theta0, theta1, n_points);
	vector<pair <double, double> > points = d.GetData();
	// Variables to store total sum over x and y
	double x_sum = 0;
	double y_sum = 0;
	// Loop though to get sum of x and y
	for (int i = 0; i < n_points; i++) {
		x_sum += points[i].first;
		y_sum += points[i].second;
	}
	// Define expected values of x and y. In my function, x draws randomly
	// from the range 0 to 10, thus the average value is 5. The exectped
	// value of y is applies the linear function to the expected value of x.
	// Note that I set the noise to be picked uniformly between -1 and 1, thus
	// these should cancel out in the expectation of y
	double x_exp = 5.0;
	double y_exp = theta1*x_exp + theta0;
	// Compute the x and y error as their average minus their expected value, then
	// take the absolute value of that
	double x_err = abs(x_exp - (x_sum / n_points));
	double y_err = abs(y_exp - (y_sum / n_points));
	// Require both errors to be small to ensure function works properly
	REQUIRE( x_err < .001 );
	REQUIRE( y_err < .001 );
}

TEST_CASE( "Test instantiating an instance of solver class" ) {
	// Generate random data
	DataCreator d(1, 1, 1);
	vector<pair <double, double> > points = d.GetData();
	// Check that solver can be instantiated
	Solver s;
	// Check that fit function works
	s.FitData(points);
	REQUIRE( 1 == 1 ); // Make naive assertion
}


