#pragma once
#include <array>

namespace ozp { namespace quadrature {


  template<size_t NDim, size_t N> struct Gaussian {};
  
  template<> struct Gaussian<NDim,1> 
  {
    Gaussian()
    {
      for (size_t i = 0; i < NDim; ++i) {
        points[i][0] = 0.0;
        weights[i][0] = 2.0;
      }
    }
    const size_t ndim = NDim;
    const size_t n = 1;
    std::array<std::array<double, n>, NDim> points;
    std::array<std::array<double, n>, NDim> weights;
  };

  template<> struct Gaussian<1,2> 
  {
    Gaussian()
    {
      for (size_t i = 0; i < NDim; ++i) {
        points[i][0] = 0.0;
        weights[i][0] = 2.0;
      }
    }
    const size_t ndim = NDim;
    const size_t n = 1;
    std::array<std::array<double, n>, NDim> points;
    std::array<std::array<double, n>, NDim> weights;
  };


}}
