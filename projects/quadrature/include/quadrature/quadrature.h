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

  template <typename T, size_t NR_DIM> using Interval = std::array<std::pair<T, T>, NR_DIM>;

  template <typename T> QuadraturePoint<T> transform(const QuadraturePoint<T> &point, const std::pair<T, T> &interval)
  {
    return QuadraturePoint<T>{
      T(0.5) * ((interval.second - interval.first) * point.position + (interval.second + interval.first)),
      T(0.5) * (interval.second - interval.first) * point.weight
    };
  }
}

namespace quadrature::detail { // compute helpers
  
  // stores N iterators and their currsponding values from another container
  template <typename ContainerType, typename IntervalType, size_t N> class PositionValuePair
  {
  public:
    using IterType = typename ContainerType::const_iterator;
    using ValueType = typename ContainerType::value_type;

    PositionValuePair(const ContainerType &container, IntervalType interval) : interval(std::move(interval))
    {
      positions.fill(begin(container));
      values.fill(transform(container.front(), interval.front()));
    }

    void set_position(size_t index, IterType new_position)
    {
      positions[index] = new_position;
      values[index] = transform(*new_position, interval[index]);
    }

    const std::array<IterType, N>& get_positions() 
    {
      return positions;
    }

    const std::array<ValueType, N>& get_values()
    {
      return values;
    }

  private:
    std::array<IterType, N> positions;
    std::array<ValueType, N> values;

    IntervalType interval;
  };

  template <typename ContainerType, typename PositionValuePairType>
  bool inc_position(const ContainerType &value_storage, PositionValuePairType &pos_value, size_t index)
  {
    if (pos_value.get_positions()[index] + 1 != end(value_storage)) {
      pos_value.set_position(index, pos_value.get_positions()[index] + 1);
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
  template <size_t NR_DIM, typename QuadratureType, typename IntervalType, typename QuadratureFun>
  void compute(const QuadratureType &quadrature, IntervalType interval, QuadratureFun fun)
  {
    auto pos_value = detail::PositionValuePair<QuadratureType, IntervalType, NR_DIM>{quadrature, std::move(interval)};

    do {
      fun(pos_value.get_values());
    } while (detail::inc_position(quadrature, pos_value, NR_DIM - 1));
  }
}

namespace quadrature::detail { // integrate helpers
  template <size_t NR_DIM> struct IntegrationHelper
  {
    template <typename ResultType, typename QuadratureType, typename IntervalType, typename QuadratureFun>
    ResultType integrate(const QuadratureType &quadrature, IntervalType interval, ResultType initial_value, QuadratureFun fun)
    {
      using QuadraturePointType = typename QuadratureType::value_type;

      auto sum = initial_value;
      compute<NR_DIM>(quadrature, interval, [&sum](const std::array<QuadraturePointType, NR_DIM> &integration_points) {
        sum = sum + fun(integration_points);
      });
      return sum;
    }
  };

  template <> struct IntegrationHelper<1>
  {
    template <typename ResultType, typename QuadratureType, typename IntervalType, typename QuadratureFun>
    ResultType integrate(const QuadratureType &quadrature, IntervalType interval, ResultType initial_value, QuadratureFun fun)
    {
      using QuadraturePointType = typename QuadratureType::value_type;

      auto sum = initial_value;
      compute<1>(quadrature, interval, [&sum, fun](const std::array<QuadraturePointType, 1> &integration_points) {
        sum = sum + fun(integration_points[0].position) * integration_points[0].weight;
      });
      return sum;
    }
  };

  template <> struct IntegrationHelper<2>
  {
    template <typename ResultType, typename QuadratureType, typename IntervalType, typename QuadratureFun>
    ResultType integrate(const QuadratureType &quadrature, IntervalType interval, ResultType initial_value, QuadratureFun fun)
    {
      using QuadraturePointType = typename QuadratureType::value_type;

      auto sum = initial_value;
      compute<2>(quadrature, interval, [&sum, fun](const std::array<QuadraturePointType, 2> &integration_points) {
        sum = sum + fun(integration_points[0].position, integration_points[1].position) * integration_points[0].weight * integration_points[1].weight;
      });
      return sum;
    }
  };

  template <> struct IntegrationHelper<3>
  {
    template <typename ResultType, typename QuadratureType, typename IntervalType, typename QuadratureFun>
    ResultType integrate(const QuadratureType &quadrature, IntervalType interval, ResultType initial_value, QuadratureFun fun)
    {
      using QuadraturePointType = typename QuadratureType::value_type;

      auto sum = initial_value;
      compute<3>(quadrature, interval, [&sum, fun](const std::array<QuadraturePointType, 3> &integration_points) {
        sum = sum + fun(integration_points[0].position, integration_points[1].position, integration_points[2].position) *
          integration_points[0].weight * integration_points[1].weight * integration_points[2].weight;
      });
      return sum;
    }
  };
}

namespace quadrature {

  template <size_t NR_DIM, size_t NR_POINTS, typename T, typename ResultType, typename QuadratureFun>
  ResultType integrate(const Quadrature<T, NR_POINTS> &quadrature, Interval<T, NR_DIM> interval, ResultType initial_value, QuadratureFun fun)
  {
    detail::IntegrationHelper<NR_DIM> helper;
    return helper.integrate(quadrature, interval, initial_value, fun);
  }
}
