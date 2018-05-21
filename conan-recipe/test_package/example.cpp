#include <iostream>
#include <quadrature\gaussian.h>

template <typename T> T fun2d(T x, T y)
{
  return x * x + y + 3;
};

int main()
{
  using namespace quadrature;

  auto interval = Interval<double, 2>{{ {-1.0, 5.0}, {1.0, 5.0} }};

  const auto REAL_VALUE = 312.0;
  double sum = integrate<2>(make_gaussian<double, 3>(), interval, 0.0, fun2d<double>);

  std::cout << "Sum should be " << REAL_VALUE << ". It is " << sum << "\n";
}