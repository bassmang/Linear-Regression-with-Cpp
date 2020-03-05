#include <lrgFileLoaderDataCreator.h>
#include <lrgNormalEquationSolverStrategy.h>
#include <lrgGradientDescentSolverStrategy.h>
#include <iostream>

// Message to send if function goes wrong or help flag is used
void help_message() {
  string message = "Welcome to my linear regression solver!\n"
                   "This tool will allow you to solve a linear "
                   "regression problem using the normal equation "
                   "or the gradient descent method. The input data "
                   "file should include (x,y) value pairs, where we "
                   "will be solving for theta0 and theta1 in the "
                   "equation:\n\n  y = theta1*x + theta0\n\n"
                   "Two sample data files are provided in this "
                   "directory with the names TestData1.txt and "
                   "TestData2.txt. If you would like to solve for "
                   "theta0 and theta1 using the normal equation "
                   "please enter the following command:\n\n  "
                   "./lrgLinReg -n [file_name.txt]\n\n where "
                   "[file_name.txt] specifies the name of the input file. "
                   "If you would like to solve for theta0 and theta1 using "
                   "the gradient descent method please enter the following "
                   "command:\n\n  ./lrgLinReg -g [file_name.txt] [epochs] "
                   "[learning_rate] [theta0_guess] [theta1_guess]\n\n "
                   "where [epochs] specifies the number of iterations for "
                   "the gradient descent, [learning_rate] specifies the "
                   "learning rate of the algorithm, and [theta0_guess] and "
                   "[theta1_guess] specify initial theta values. If you "
                   "would like to see this message again, please enter:"
                   "\n\n  ./lrgLinReg [-h/--help]\n";
  cout << message << endl;
}

int main(int argc, char** argv)
{
  // Exit and send help message if less than 3 arguments or help flags
  if (argc < 3 || !strcmp(argv[1],"-h") || !strcmp(argv[1],"--help")) {
    help_message();
    return -1;
  }
  string file_name = argv[2]; // Get file name
  try {
    // Read file and load points
    FileDataCreator fdc(file_name);
    vector<point> points = fdc.GetData();
    // If the -n flag is used, apply normal equation
    if (!strcmp(argv[1],"-n")) {
      // If there aren't three arguments, the input is not accurate
      if (argc != 3) {
        string err_msg = "\nSorry this is the wrong number of arguments"
                         " for the normal equation.\n";
        cout << err_msg << endl;
        help_message();
        return -1;
      }
      // Solve using normal equation and print message
      NormalSolver solver;
      point thetas = solver.FitData(points);
      cout << "Using normal equation yields the following results:" << endl;
      cout << "theta0 = " << thetas.first << endl;
      cout << "theta1 = " << thetas.second << endl;
      return 0;
    // If the -g flag is used, apply gradient descent method
    } else if (!strcmp(argv[1],"-g")) {
      // If there aren't seven arguments, the input is not accurate
      if (argc != 7) {
        string err_msg = "\nSorry this is the wrong number of arguments"
                         " for gradient descent.\n";
        cout << err_msg << endl;
        help_message();
        return -1;
      }
      // Solve using gradient descent and print message
      int epochs = atoi(argv[3]);
      double alpha = atof(argv[4]);
      double t0_guess = atof(argv[5]);
      double t1_guess = atof(argv[6]);
      GradientSolver solver = GradientSolver(epochs,alpha,t0_guess,t1_guess);
      point thetas = solver.FitData(points);
      cout << "Using gradient descent yields the following results:" << endl;
      cout << "theta0 = " << thetas.first << endl;
      cout << "theta1 = " << thetas.second << endl;
      return 0;
    // If the -n or -g flags are not given, the inpur is incorrect
    } else {
      string err_msg = "\nYou must specify whether you would like to use the"
                       "normal equation or gradient descent.\n";
      cout << err_msg << endl;
      help_message();
      return -1;
    }
  // Catch error if file cannot be read, and send help message
  } catch (std::exception& e) {
    cerr << "\nCaught Exception: " << e.what() << "\n\n";
    help_message();
    return -1;
  // Catch all other exceptions
  } catch (...) {
    cerr << "\nCaught Exception: Unknown exception" << "\n\n";
    help_message();
  }
  return 0;
}