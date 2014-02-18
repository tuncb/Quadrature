#pragma once

namespace ozp { namespace quadrature {

  namespace detail {
    template <typename Quadrature, unsigned int Dim> struct QuadratureHelper {};

    template <typename Quadrature> struct QuadratureHelper<Quadrature, 1> {
      template <typename LambdaType> void integrate(LambdaType fun)
      {
        Quadrature q;
        for (unsigned int i = 0; i < q.n(); ++i) {fun(q.points[i], q.weights[i]);}
      }
    };

    template <typename Quadrature> struct QuadratureHelper<Quadrature, 2> {
      template <typename LambdaType> void integrate(LambdaType fun)
      {
        Quadrature q;
        const auto n = q.n();
        for (unsigned int i = 0; i < n; ++i) 
          for (unsigned int j = 0; j < n; ++j) 
          {fun(q.points[i], q.points[j], q.weights[i], q.weights[j]); }
      }
    };

    template <typename Quadrature> struct QuadratureHelper<Quadrature, 3> {
      template <typename LambdaType> void integrate(LambdaType fun)
      {
        Quadrature q;
        const auto n = q.n();
        for (unsigned int i = 0; i < n; ++i) 
          for (unsigned int j = 0; j < n; ++j) 
            for (unsigned int k = 0; k < n; ++k) 
            {fun(q.points[i], q.points[j], q.points[k], q.weights[i], q.weights[j],q.weights[k]); }
      }
    };
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// <summary> Integrates the given functin. </summary>
  ///
  /// <typeparam name="QuadratureType"> Type of the quadrature type. </typeparam>
  /// <typeparam name="N">              Number of dimentions  </typeparam>
  /// <typeparam name="LambdaType">     Type of the integration function. </typeparam>
  /// <param name="fun"> The fun. </param>
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  template <typename QuadratureType, unsigned int N, typename LambdaType> void integrate(LambdaType fun)
  {
    detail::QuadratureHelper<QuadratureType, N> helper;
    helper.integrate(fun);
  }

}}