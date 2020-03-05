PHAS0100Assignment1 Linear Regression
------------------

Purpose
-------

The purpose of this project is to solve a linear regression of the form:

y = theta1*x + theta0

Given a text document which contains a column of x values, and a column of y values.

Credits
-------

This project was developed by Griffin Bassman.

Build Instructions
------------------

This project itself can be built if you just want to test it. In Linux terms that
would be:
```
git clone https://github.com/bassmang/PHAS0100Assignment1/
mkdir PHAS0100Assignment1-Build
cd PHAS0100Assignment1-Build
cmake ../PHAS0100Assignment1
make
```

How to Use
------------------

Once the project has been properly built and you are in the PHAS0100Assignment1-Build directory, type:
```
cd bin
```
In order to get in the same directory as the app. In this directory, you will find two files, TestData1.txt and TestData2.txt which are sample files to perform a linear regression. You can either perform a linear regression using the normal equation or gradient descent. If you would like the use the normal equation, type:
```
./lrgLinReg -n [file_name.txt]
```
If you would like to use the gradient descent method, type:
```
./lrgLinReg -g [file_name.txt] [epochs] [learning_rate] [theta0_guess] [theta1_guess]
```
Where [epochs] specifies the number of iterations, [learning_rate] specifies the learning rate of the algorithm, and [theta0_guess] and [theta1_guess] specify initial values for these parameter. If you would like more details please type:
```
./lrgLinReg [-h/--help]
```
