#pragma once
#include <array>

namespace ozp { namespace quadrature {




  template<unsigned int N> struct Gaussian {};
  
  template<> struct Gaussian<1> 
  {
    Gaussian()
    {
      points[0] = 0.0;
      weights[0] = 2.0;
    }
    unsigned int n()    const {return 1;}
    std::array<double, 1> points;
    std::array<double, 1> weights;
  };

  template<> struct Gaussian<2> 
  {
    Gaussian()
    {
      points[0] =  0.57735026919;
      points[1] = -0.57735026919;

      weights[0] = 1;
      weights[1] = 1;
    }
    unsigned int n() const {return 2;}
    std::array<double, 2> points;
    std::array<double, 2> weights;
  };

}}
