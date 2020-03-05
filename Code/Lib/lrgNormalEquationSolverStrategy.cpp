#include "lrgNormalEquationSolverStrategy.h"
#include "../3rdParty/Eigen-3.2.2.1/Eigen/Dense"

using namespace Eigen;

NormalSolver::NormalSolver() { }

point NormalSolver::FitData(vector<point> points) {
	Matrix<double,Dynamic,2> X(points.size(),2); // Create matrix to hold X
	Matrix<double,Dynamic,1> y(points.size(),1); // Create matrix to hold Y
	// Copy points over to each of the matrices. Set the first column of X to all
	// 1s for constant term in linear regression.
	for (int i = 0; i < points.size(); i++) {
		X(i,0) = 1;
		X(i,1) = points[i].first;
		y(i,0) = points[i].second;
	}
	// Get thetas by performing Normal Equation
	Matrix<double,2,1> thetas = (X.transpose() * X).inverse() * X.transpose() * y;
	// Return thetas as a pair of both theta values
	return point(thetas(0,0), thetas(1,0));;
}