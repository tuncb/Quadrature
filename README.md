Quadrature
=======
Introduction
-----------
A small library for implementation of quadrature rules.

* quadrature[@github](https://github.com/onezeroplus/Quadrature "")
* quadrature[@conan](https://dl.bintray.com/tuncb/stable)

Prerequests
----------
A c++17 compiler

Installation
------
Header only. Just include the files under the include folder

or use conan io -> 
* quadrature[@conan](https://dl.bintray.com/tuncb/pangea)
* quadrature/1.0.0@tuncb/pangea

Documentation
-----------
```cpp
#include <quadrature/quadrature.h>
#include <quadrature/gaussian.h> // currently only Gaussian quadrature with up to 6 points is available.

template <typename T> T fun(T x) 
{ 
  return 2 * x * x + 3 * x + T(5.0); 
};

template <typename T> T fun2d(T x, T y)
{
  return x * x + y + 3;
};

template <typename T> T fun3d(T x, T y, T z)
{
  return x + y * y + 3 * z * z * z  + 3;
};

auto interval_1d = Interval<double, 1>{{ {-2.0, 2.0} }};
auto interval_2d = Interval<double, 2>{{ {-1.0, 5.0}, {1.0, 5.0} }};
auto interval_3d = Interval<double, 3>{{ {1, 2}, {-0.5, -0.25}, {-3.5, 7.5} }};

// make_gaussian<double, 4> -> Gauss quadrature with four points
auto sum1d = integrate<1>(make_gaussian<double, 4>(), interval, 0.0, fun<double>)
auto sum2d = integrate<2>(make_gaussian<double, 4>(), interval, 0.0, fun2d<double>) 
auto sum3d = integrate<3>(make_gaussian<double, 4>(), interval, 0.0, fun3d<double>)
```
