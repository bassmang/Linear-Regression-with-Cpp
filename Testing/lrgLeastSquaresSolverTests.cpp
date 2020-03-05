#include "catch.hpp"
#include "lrgLinearDataCreator.h"
#include "lrgNormalEquationSolverStrategy.h"
#include "lrgGradientDescentSolverStrategy.h"
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
	vector<point> points = d.GetData();
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
	REQUIRE( x_err < .01 );
	REQUIRE( y_err < .01 );
}

TEST_CASE( "Test instantiating an instance of Normal Equation solver class" ) {
	// Generate random data
	DataCreator d(1, 1, 1);
	vector<point> points = d.GetData();
	// Check that solver can be instantiated
	NormalSolver s;
	// Check that fit function works
	s.FitData(points);
	REQUIRE( 1 == 1 ); // Make naive assertion
}

TEST_CASE( "Test Normal Equation with generated data both positive thetas" ) {
	// Set random values for theta0, theta1, and number of points
	double theta0 = 50.0;
	double theta1 = 0.5;
	double n_points = 1000000;
	// Generate data
	DataCreator d(theta0, theta1, n_points);
	vector<point> points = d.GetData();
	NormalSolver s; // Instantiate solver
	// Solve for thetas using normal equation
	point norm_thetas = s.FitData(points);
	// Find difference in real theta values in those computed through
	// normal equation
	double theta0_err = abs(theta0 - norm_thetas.first);
	double theta1_err = abs(theta1 - norm_thetas.second);
	// Assert that these values are very close
	REQUIRE( theta0_err < .01 );
	REQUIRE( theta1_err < .01 );
}

TEST_CASE( "Test Normal Equation with generated data both negative thetas" ) {
	// Set random values for theta0, theta1, and number of points
	double theta0 = -10.0;
	double theta1 = -2.5;
	double n_points = 1000000;
	// Generate data
	DataCreator d(theta0, theta1, n_points);
	vector<point> points = d.GetData();
	NormalSolver s; // Instantiate solver
	// Solve for thetas using normal equation
	point norm_thetas = s.FitData(points);
	// Find difference in real theta values in those computed through
	// normal equation
	double theta0_err = abs(theta0 - norm_thetas.first);
	double theta1_err = abs(theta1 - norm_thetas.second);
	// Assert that these values are very close
	REQUIRE( theta0_err < .01 );
	REQUIRE( theta1_err < .01 );
}

TEST_CASE( "Test Normal Equation with generated data both 0 thetas" ) {
	// Set random values for theta0, theta1, and number of points
	double theta0 = 0.0;
	double theta1 = 0.0;
	double n_points = 1000000;
	// Generate data
	DataCreator d(theta0, theta1, n_points);
	vector<point> points = d.GetData();
	NormalSolver s; // Instantiate solver
	// Solve for thetas using normal equation
	point norm_thetas = s.FitData(points);
	// Find difference in real theta values in those computed through
	// normal equation
	double theta0_err = abs(theta0 - norm_thetas.first);
	double theta1_err = abs(theta1 - norm_thetas.second);
	// Assert that these values are very close
	REQUIRE( theta0_err < .01 );
	REQUIRE( theta1_err < .01 );
}

TEST_CASE( "Test instantiating an instance of Gradient Descent solver class" ) {
	// Generate random data
	DataCreator d(1, 1, 1);
	vector<point> points = d.GetData();
	// Check that solver can be instantiated
	GradientSolver s(1, 1, 1, 1);
	// Check that fit function works
	s.FitData(points);
	REQUIRE( 1 == 1 ); // Make naive assertion
}

TEST_CASE( "Test Gradient Descent with generated data both positive thetas" ) {
	// Set random values for theta0, theta1, and number of points
	double theta0 = 50.0;
	double theta1 = 0.5;
	double n_points = 100000;
	// Generate data
	DataCreator d(theta0, theta1, n_points);
	vector<point> points = d.GetData();
	// Set parameters for gradient solver
	int epochs = 10000; // Sufficiently high number of epochs
	double learning_rate = .01; // Sufficently low learning rate
	double theta0_init = 0.0; // Uninformed guess of theta0
	double theta1_init = 0.0; // Uninformed guess of theta1
	// Initialize gradient solver with given parameters
	GradientSolver s(epochs, learning_rate, theta0_init, theta1_init);
	// Solve for thetas using normal equation
	point grad_thetas = s.FitData(points);
	// Find difference in real theta values in those computed through
	// normal equation
	double theta0_err = abs(theta0 - grad_thetas.first);
	double theta1_err = abs(theta1 - grad_thetas.second);
	// Assert that these values are very close
	REQUIRE( theta0_err < .01 );
	REQUIRE( theta1_err < .01 );
}

TEST_CASE( "Test Gradient Descent with generated data both negative thetas" ) {
	// Set random values for theta0, theta1, and number of points
	double theta0 = -10.0;
	double theta1 = -2.5;
	double n_points = 100000;
	// Generate data
	DataCreator d(theta0, theta1, n_points);
	vector<point> points = d.GetData();
	// Set parameters for gradient solver
	int epochs = 10000; // Sufficiently high number of epochs
	double learning_rate = .01; // Sufficently low learning rate
	double theta0_init = 2.0; // Uninformed guess of theta0
	double theta1_init = 3.6; // Uninformed guess of theta1
	// Initialize gradient solver with given parameters
	GradientSolver s(epochs, learning_rate, theta0_init, theta1_init);
	// Solve for thetas using normal equation
	point grad_thetas = s.FitData(points);
	// Find difference in real theta values in those computed through
	// normal equation
	double theta0_err = abs(theta0 - grad_thetas.first);
	double theta1_err = abs(theta1 - grad_thetas.second);
	// Assert that these values are very close
	REQUIRE( theta0_err < .01 );
	REQUIRE( theta1_err < .01 );
}

TEST_CASE( "Test Gradient Descent with generated data both 0 thetas" ) {
	// Set random values for theta0, theta1, and number of points
	double theta0 = 0.0;
	double theta1 = 0.0;
	double n_points = 100000;
	// Generate data
	DataCreator d(theta0, theta1, n_points);
	vector<point> points = d.GetData();
	// Set parameters for gradient solver
	int epochs = 10000; // Sufficiently high number of epochs
	double learning_rate = .01; // Sufficently low learning rate
	double theta0_init = -10.0; // Uninformed guess of theta0
	double theta1_init = 7.9; // Uninformed guess of theta1
	// Initialize gradient solver with given parameters
	GradientSolver s(epochs, learning_rate, theta0_init, theta1_init);
	// Solve for thetas using normal equation
	point grad_thetas = s.FitData(points);
	// Find difference in real theta values in those computed through
	// normal equation
	double theta0_err = abs(theta0 - grad_thetas.first);
	double theta1_err = abs(theta1 - grad_thetas.second);
	// Assert that these values are very close
	REQUIRE( theta0_err < .01 );
	REQUIRE( theta1_err < .01 );
}