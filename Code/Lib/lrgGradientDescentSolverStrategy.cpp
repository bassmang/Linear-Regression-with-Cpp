#include "lrgGradientDescentSolverStrategy.h"
#include "../3rdParty/Eigen-3.2.2.1/Eigen/Dense"

using namespace Eigen;

GradientSolver::GradientSolver(int iters, double lr, double t0_guess, double t1_guess) {
	epochs = iters;
	alpha = lr;
	theta0_init = t0_guess;
	theta1_init = t1_guess;
}

point GradientSolver::FitData(vector<point> points) {
	int n = points.size(); // Define number of points
	double theta0 = theta0_init; // Initialize theta0
	double theta1 = theta1_init; // Initialize theta1
	// Iterate for the number of epochs
	for (int iter = 0; iter < epochs; iter++) {
		double d_theta0 = 0; // Set dervative w.r.t theta0 to 0
		double d_theta1 = 0; // Set dervative w.r.t theta1 to 0
		// Iterate through points to compute derivatives
		for (int i = 0; i < n; i++) {
			double y_pred = theta1*points[i].first + theta0; // Prediction of y
			double y_err = y_pred - points[i].second; // Error in prediction
			d_theta0 += y_err; // Add error to derivative of theta0
			d_theta1 += points[i].first*y_err; // Add error*x_i to derivative of theta1
		}
		// Scale derivatives by number of data points
		d_theta0 /= n;
		d_theta1 /= n;
		// Update both thetas down gradient using learning rate
		theta0 -= alpha*d_theta0;
		theta1 -= alpha*d_theta1;
	}
	return point(theta0, theta1);;
}