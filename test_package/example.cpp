#include <iostream>
#include <quadrature\Gaussian.h>

double compute_pos(double x) 
{ 
  return x + 1.0;
}

int main()
{
  double sum = 0.0;
  quadrature::integrate<quadrature::Gaussian<2>, 1>([&](double ip1, double w1) {
    sum += compute_pos(ip1) * w1;
  });

  std::cout << "Sum should be 2.0. It is " << sum << "\n";
}