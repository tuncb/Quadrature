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

  template<> struct Gaussian<3> 
  {
    Gaussian()
    {
      points[0] =  0.77459666924;
      points[1] = -0.77459666924;
      points[2] = 0.0;

      weights[0] = 0.55555555555;
      weights[1] = 0.55555555555;
      weights[2] = 0.88888888888;
    }
    unsigned int n() const {return 3;}
    std::array<double, 3> points;
    std::array<double, 3> weights;
  };

  template<> struct Gaussian<4> 
  {
    Gaussian()
    {
      points[0] = -0.3399810435848563;
      points[1] =  0.3399810435848563;
      points[2] = -0.8611363115940526;
      points[3] =  0.8611363115940526;

      weights[0] = 0.6521451548625461;
      weights[1] = 0.6521451548625461;
      weights[2] = 0.3478548451374538;
      weights[3] = 0.3478548451374538;
    }
    unsigned int n() const {return 4;}
    std::array<double, 4> points;
    std::array<double, 4> weights;
  };

  template<> struct Gaussian<5> 
  {
    Gaussian()
    {
      points[0] =  0.0;
      points[1] = -0.5384693101056831;
      points[2] =  0.5384693101056831;
      points[3] = -0.9061798459386640;
      points[4] =  0.9061798459386640;

      weights[0] = 0.5688888888888889;
      weights[1] = 0.4786286704993665;
      weights[2] = 0.4786286704993665;
      weights[3] = 0.2369268850561891;
      weights[4] = 0.2369268850561891;
    }
    unsigned int n() const {return 5;}
    std::array<double, 5> points;
    std::array<double, 5> weights;
  };

  template<> struct Gaussian<6> 
  {
    Gaussian()
    {
      points[0] =  0.6612093864662645;
      points[1] = -0.6612093864662645;
      points[2] = -0.2386191860831969;
      points[3] =  0.2386191860831969;
      points[4] = -0.9324695142031521;
      points[5] =  0.9324695142031521;

      weights[0] = 0.3607615730481386;
      weights[1] = 0.3607615730481386;
      weights[2] = 0.4679139345726910;
      weights[3] = 0.4679139345726910;
      weights[4] = 0.1713244923791704;
      weights[5] = 0.1713244923791704;
    }
    unsigned int n() const {return 6;}
    std::array<double, 6> points;
    std::array<double, 6> weights;
  };


}}
