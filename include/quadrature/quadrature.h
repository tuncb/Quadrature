#pragma once
#include <vector>

namespace quadrature {

  namespace detail {
    template <typename Quadrature, unsigned int Dim> struct QuadratureHelper {};

    template <typename Quadrature> struct QuadratureHelper<Quadrature, 1> {
      template <typename LambdaType> void integrate(const Quadrature& q, LambdaType fun)
      {
        for (unsigned int i = 0; i < q.n(); ++i) {fun(q.points[i], q.weights[i]);}
      }
    };

    template <typename Quadrature> struct QuadratureHelper<Quadrature, 2> {
      template <typename LambdaType> void integrate(const Quadrature& q, LambdaType fun)
      {
        const auto n = q.n();
        for (unsigned int i = 0; i < n; ++i) 
          for (unsigned int j = 0; j < n; ++j) 
          {fun(q.points[i], q.points[j], q.weights[i], q.weights[j]); }
      }
    };

    template <typename Quadrature> struct QuadratureHelper<Quadrature, 3> {
      template <typename LambdaType> void integrate(const Quadrature& q, LambdaType fun)
      {
        const auto n = q.n();
        for (unsigned int i = 0; i < n; ++i) 
          for (unsigned int j = 0; j < n; ++j) 
            for (unsigned int k = 0; k < n; ++k) 
            {fun(q.points[i], q.points[j], q.points[k], q.weights[i], q.weights[j],q.weights[k]); }
      }
    };
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// <summary> Quadrature base class. </summary>
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  class Quadrature
  {
  public:
    Quadrature(unsigned int n)  : _n(n) {
      this->points.resize(_n);
      this->weights.resize(_n);
    } 
    
    std::vector<double> points;
    std::vector<double> weights;

    unsigned int n() const {return _n;}
  private:
    unsigned int _n;
  };

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// <summary> Integrates the given function. </summary>
  ///
  /// <typeparam name="QuadratureType"> Type of the quadrature type. </typeparam>
  /// <typeparam name="N">              Number of dimentions  </typeparam>
  /// <typeparam name="LambdaType">     Type of the integration function. </typeparam>
  /// <param name="fun"> the integration function. </param>
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  template <typename QuadratureType, unsigned int N, typename LambdaType> void integrate(LambdaType fun)
  {
    QuadratureType q;
    detail::QuadratureHelper<QuadratureType, N> helper;
    helper.integrate(q, fun);
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// <summary>Integrates the given function with the given quadrature variable </summary>
  ///
  /// <typeparam name="QuadratureType">Type of the quadrature type.</typeparam>
  /// <typeparam name="N">             Number of dimentions</typeparam>
  /// <typeparam name="LambdaType">    Type of the integration function.</typeparam>
  /// <param name="q">  Quadrature .</param>
  /// <param name="fun">the integration function.</param>
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  template <unsigned int N, typename QuadratureType, typename LambdaType> void integrate(const QuadratureType& q, LambdaType fun)
  {
    detail::QuadratureHelper<QuadratureType, N> helper;
    helper.integrate(q, fun);
  }

}