#pragma once
#include <quadrature\quadrature.h>

namespace quadrature::detail {
  template <typename T, size_t NR_POINTS> class GaussianHelper {};

  template <typename T> struct GaussianHelper<T, 1>
  {
    Quadrature<T, 1> make_gaussian() 
    {
      return { {T(0.0), T(2.0)} };
    }
  };

  template <typename T> struct GaussianHelper<T, 2>
  {
    Quadrature<T, 2> make_gaussian()
    {
      return {
        QuadraturePoint<T>{T(0.57735026919), T(1.0)},
        QuadraturePoint<T>{T(-0.57735026919), T(1.0)}
      };
    }
  };

  template <typename T> struct GaussianHelper<T, 3>
  {
    Quadrature<T, 3> make_gaussian()
    {
      return {
        QuadraturePoint<T>{T(0.77459666924), T(0.55555555555)},
        QuadraturePoint<T>{T(-0.77459666924), T(0.55555555555)},
        QuadraturePoint<T>{T(0.0), T(0.88888888888)}
      };
    }
  };
}

namespace quadrature {
  template <typename T, size_t NR_POINTS> Quadrature<T, NR_POINTS> make_gaussian()
  {
    detail::GaussianHelper<T, NR_POINTS> helper;
    return helper.make_gaussian();
  }
}
