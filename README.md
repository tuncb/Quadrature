Quadrature
=======
Introduction
-----------
A small library for implementation of quadrature rules.

* quadrature[@github](https://github.com/onezeroplus/Quadrature "")
* quadrature[@conan](https://dl.bintray.com/tuncb/pangea)

Prerequests
----------
none

Installation
------
Header only. Just include the files under the include folder

or use conan io -> 
* quadrature[@conan](https://dl.bintray.com/tuncb/pangea)
* quadrature/0.1.0@tuncb/pangea

Documentation
-----------
```cpp
#include <quadrature/quadrature.h>
#include <quadrature/Gaussian.h> // currently only Gaussian quadrature with up to 6 points is available.

// for 1 dimension
ozp::quadrature::integrate<ozp::quadrature::Gaussian<3>, 1>([](double ip1, double w1){
// integration function here
});

// for 2 dimensions
ozp::quadrature::integrate<ozp::quadrature::Gaussian<3>, 2>([](double ip1, double ip2, double w1, double w2){
// integration function here
});

// for 3 dimensions
ozp::quadrature::integrate<ozp::quadrature::Gaussian<3>, 3>([](double ip1, double ip2, double ip3, double w1, double w2, double w3){
// integration function here
});
```

There is also a variable version of integrate function
```cpp
ozp::quadrature::Gaussian<3> gauss;
ozp::quadrature::integrate<3>(gauss, [](double ip1, double ip2, double ip3, double w1, double w2, double w3){
// integration function here
});
```
All quadrature implementations are based on ozp::quadrature::Quadrature class.
```cpp
ozp::quadrature::Quadrature* quad;
if (is_gauss_2) quad = new ozp::quadrature::Gaussian<2>();
else quad = new ozp::quadrature::Gaussian<3>();
```

