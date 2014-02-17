Quadrature
=======
Introduction
-----------
A small library for implementation of quadrature rules.
Prerequests
----------
none
* Tests are based on Boost.Test

Installation
------
Header only 
Documentation
-----------
~~~~~cpp
#include <quadrature/quadrature.h>
#include <quadrature/Gaussian.h> // currently only gaussian quadrature with upto 2 points is available.

// for 1 dimention
ozp::quadrature::integrate<ozp::quadrature::Gaussian<2>, 1>([](double ip1, double w1){
// integration function here
});

// for 2 dimentions
ozp::quadrature::integrate<ozp::quadrature::Gaussian<2>, 2>([](double ip1, double ip2, double w1, double w2){
// integration function here
});

// for 3 dimentions
ozp::quadrature::integrate<ozp::quadrature::Gaussian<2>, 3>([](double ip1, double ip2, double ip3, double w1, double w2, double w3){
// integration function here
});
~~~~
