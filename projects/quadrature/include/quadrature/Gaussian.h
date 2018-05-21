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

  template <typename T> struct GaussianHelper<T, 4>
  {
    Quadrature<T, 4> make_gaussian()
    {
      return {
        QuadraturePoint<T>{T(-0.3399810435848563), T(0.6521451548625461)},
        QuadraturePoint<T>{T(0.3399810435848563), T(0.6521451548625461)},
        QuadraturePoint<T>{T(-0.8611363115940526), T(0.3478548451374538)},
        QuadraturePoint<T>{T(0.8611363115940526), T(0.3478548451374538)}
      };
    }
  };

  template <typename T> struct GaussianHelper<T, 5>
  {
    Quadrature<T, 5> make_gaussian()
    {
      return {
        QuadraturePoint<T>{T(0.0), T(0.5688888888888889)},
        QuadraturePoint<T>{T(-0.5384693101056831), T(0.4786286704993665)},
        QuadraturePoint<T>{T(0.5384693101056831), T(0.4786286704993665)},
        QuadraturePoint<T>{T(-0.9061798459386640), T(0.2369268850561891)},
        QuadraturePoint<T>{T(0.9061798459386640), T(0.2369268850561891)}
      };
    }
  };

  template <typename T> struct GaussianHelper<T, 6>
  {
    Quadrature<T, 6> make_gaussian()
    {
      return {
        QuadraturePoint<T>{T(0.6612093864662645), T(0.3607615730481386)},
        QuadraturePoint<T>{T(-0.6612093864662645), T(0.3607615730481386)},
        QuadraturePoint<T>{T(-0.2386191860831969), T(0.4679139345726910)},
        QuadraturePoint<T>{T(0.2386191860831969), T(0.4679139345726910)},
        QuadraturePoint<T>{T(-0.9324695142031521), T(0.1713244923791704)},
        QuadraturePoint<T>{T(0.9324695142031521), T(0.1713244923791704)}
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
