#pragma once
#include <array>

namespace quadrature {

  template <typename T> struct QuadraturePoint
  {
    using value_type = T;

    value_type position;
    value_type weight;
  };

  template <typename T, size_t NR_POINTS> using Quadrature = std::array<QuadraturePoint<T>, NR_POINTS>;

  template <typename T> struct IntervalRange
  {
    T first;
    T last;
  };

  template <typename T, size_t NR_DIM> using Interval = std::array<IntervalRange<T>, NR_DIM>;
}

namespace quadrature::detail { // compute helpers
  
  // stores N iterators and their currsponding values from another container
  template <typename ContainerType, size_t N> struct PositionValuePair
  {
    using IterType = typename ContainerType::const_iterator;
    using ValueType = typename ContainerType::value_type;

    PositionValuePair(const ContainerType &container)
    {
      positions.fill(begin(container));
      values.fill(*begin(container));
    }

    void set_position(size_t index, IterType new_position)
    {
      positions[index] = new_position;
      values[index] = *new_position;
    }

    std::array<IterType, N> positions;
    std::array<ValueType, N> values;
  };

  template <typename ContainerType, size_t N> bool inc_position(const ContainerType &value_storage, PositionValuePair<ContainerType, N> &pos_value, size_t index)
  {
    if (pos_value.positions[index] + 1 != end(value_storage)) {
      pos_value.set_position(index, pos_value.positions[index] + 1);
      return true;
    }

    if (index != 0) {
      pos_value.set_position(index, begin(value_storage));
      return inc_position(value_storage, pos_value, index - 1);
    }

    return false;
  }
}

namespace quadrature {
  template <size_t NR_DIM, typename QuadratureType, typename QuadratureFun>
  void compute(const QuadratureType &quadrature, QuadratureFun fun)
  {
    auto pos_value = detail::PositionValuePair<QuadratureType, NR_DIM>{ quadrature };

    do {
      fun(pos_value.values);
    } while (detail::inc_position(quadrature, pos_value, NR_DIM - 1));
  }
}

namespace quadrature::detail { // integrate helpers
  template <size_t NR_DIM> struct IntegrationHelper
  {
    template <typename ResultType, typename QuadratureType, typename QuadratureFun>
    ResultType integrate(const QuadratureType &quadrature, ResultType initial_value, QuadratureFun fun)
    {
      using QuadraturePointType = typename QuadratureType::value_type;

      auto sum = initial_value;
      compute<NR_DIM>(quadrature, [&sum](const std::array<QuadraturePointType, NR_DIM> &integration_points) {
        sum = sum + fun(integration_points);
      });
      return sum;
    }
  };

  template <> struct IntegrationHelper<1>
  {
    template <typename ResultType, typename QuadratureType, typename QuadratureFun>
    ResultType integrate(const QuadratureType &quadrature, ResultType initial_value, QuadratureFun fun)
    {
      using QuadraturePointType = typename QuadratureType::value_type;

      auto sum = initial_value;
      compute<1>(quadrature, [&sum, fun](const std::array<QuadraturePointType, 1> &integration_points) {
        sum = sum + fun(integration_points[0].position) * integration_points[0].weight;
      });
      return sum;
    }
  };

  template <> struct IntegrationHelper<2>
  {
    template <typename ResultType, typename QuadratureType, typename QuadratureFun>
    ResultType integrate(const QuadratureType &quadrature, ResultType initial_value, QuadratureFun fun)
    {
      using QuadraturePointType = typename QuadratureType::value_type;

      auto sum = initial_value;
      compute<2>(quadrature, [&sum, fun](const std::array<QuadraturePointType, 2> &integration_points) {
        sum = sum + fun(integration_points[0].position, integration_points[1].position) * integration_points[0].weight * integration_points[1].weight;
      });
      return sum;
    }
  };

  template <> struct IntegrationHelper<3>
  {
    template <typename ResultType, typename QuadratureType, typename QuadratureFun>
    ResultType integrate(const QuadratureType &quadrature, ResultType initial_value, QuadratureFun fun)
    {
      using QuadraturePointType = typename QuadratureType::value_type;

      auto sum = initial_value;
      compute<3>(quadrature, [&sum, fun](const std::array<QuadraturePointType, 3> &integration_points) {
        sum = sum + fun(integration_points[0].position, integration_points[1].position, integration_points[2].position) *
          integration_points[0].weight * integration_points[1].weight * integration_points[2].weight;
      });
      return sum;
    }
  };
}

namespace quadrature {

  template <size_t NR_DIM, typename QuadratureType, typename ResultType, typename QuadratureFun>
  ResultType integrate(const QuadratureType &quadrature, ResultType initial_value, QuadratureFun fun)
  {
    detail::IntegrationHelper<NR_DIM> helper;
    return helper.integrate(quadrature, initial_value, fun);
  }
}