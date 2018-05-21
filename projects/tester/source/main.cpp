#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <quadrature\gaussian.h>

using namespace quadrature;

template <typename T> T fun(T x) 
{ 
  return 2 * x * x + 3 * x + T(5.0); 
};

template <typename T> T fun2d(T x, T y)
{
  return x * x + y + 3;
};

template <typename T> T fun3d(T x, T y, T z)
{
  return x + y * y + 3 * z * z * z  + 3;
};

TEST_CASE("quadrature integrate with Gauss quadrature", "[integrate]") 
{
  
  SECTION("#Dimension = 1, T = double")
  {   
    const auto REAL_VALUE = 92.0 / 3.0;

    auto interval = Interval<double, 1>{{ {-2.0, 2.0} }};

    REQUIRE(integrate<1>(make_gaussian<double, 1>(), interval, 0.0, fun<double>) == Approx(REAL_VALUE).margin(11)); // single point gauss is not enough to get the correct result
    REQUIRE(integrate<1>(make_gaussian<double, 2>(), interval, 0.0, fun<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<1>(make_gaussian<double, 3>(), interval, 0.0, fun<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<1>(make_gaussian<double, 4>(), interval, 0.0, fun<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<1>(make_gaussian<double, 5>(), interval, 0.0, fun<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<1>(make_gaussian<double, 6>(), interval, 0.0, fun<double>) == Approx(REAL_VALUE));
  }

  SECTION("#Dimension = 1, T = float")
  {
    const auto REAL_VALUE = 92.0f / 3.0f;

    auto interval = Interval<float, 1>{{ {-2.0f, 2.0f} }};

    REQUIRE(integrate<1>(make_gaussian<float, 1>(), interval, 0.0f, fun<float>) == Approx(REAL_VALUE).margin(11)); // single point gauss is not enough to get the correct result
    REQUIRE(integrate<1>(make_gaussian<float, 2>(), interval, 0.0f, fun<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<1>(make_gaussian<float, 3>(), interval, 0.0f, fun<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<1>(make_gaussian<float, 4>(), interval, 0.0f, fun<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<1>(make_gaussian<float, 5>(), interval, 0.0f, fun<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<1>(make_gaussian<float, 6>(), interval, 0.0f, fun<float>) == Approx(REAL_VALUE));
  }
  
  SECTION("#Dimension = 2, T = double")
  {
    const auto REAL_VALUE = 312.0;

    auto interval = Interval<double, 2>{{ {-1.0, 5.0}, {1.0, 5.0} }};

    REQUIRE(integrate<2>(make_gaussian<double, 1>(), interval, 0.0, fun2d<double>) == Approx(REAL_VALUE).margin(80)); // single point gauss is not enough to get the correct result
    REQUIRE(integrate<2>(make_gaussian<double, 2>(), interval, 0.0, fun2d<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<2>(make_gaussian<double, 3>(), interval, 0.0, fun2d<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<2>(make_gaussian<double, 4>(), interval, 0.0, fun2d<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<2>(make_gaussian<double, 5>(), interval, 0.0, fun2d<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<2>(make_gaussian<double, 6>(), interval, 0.0, fun2d<double>) == Approx(REAL_VALUE));
  }
  
  SECTION("#Dimension = 2, T = float")
  {
    const auto REAL_VALUE = 312.0f;

    auto interval = Interval<float, 2>{{ {-1.0f, 5.0f}, {1.0f, 5.0f} }};

    REQUIRE(integrate<2>(make_gaussian<float, 1>(), interval, 0.0f, fun2d<float>) == Approx(REAL_VALUE).margin(110)); // single point gauss is not enough to get the correct result
    REQUIRE(integrate<2>(make_gaussian<float, 2>(), interval, 0.0f, fun2d<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<2>(make_gaussian<float, 3>(), interval, 0.0f, fun2d<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<2>(make_gaussian<float, 4>(), interval, 0.0f, fun2d<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<2>(make_gaussian<float, 5>(), interval, 0.0f, fun2d<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<2>(make_gaussian<float, 6>(), interval, 0.0f, fun2d<float>) == Approx(REAL_VALUE));
  }
  
  SECTION("#Dimension = 3, T = double")
  {
    const auto REAL_VALUE = 577.9010;

    auto interval = Interval<double, 3>{{ {1, 2}, {-0.5, -0.25}, {-3.5, 7.5} }};

    REQUIRE(integrate<3>(make_gaussian<double, 1>(), interval, 0.0, fun3d<double>) == Approx(REAL_VALUE).margin(500)); // single point gauss is not enough to get the correct result
    REQUIRE(integrate<3>(make_gaussian<double, 2>(), interval, 0.0, fun3d<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<3>(make_gaussian<double, 3>(), interval, 0.0, fun3d<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<3>(make_gaussian<double, 4>(), interval, 0.0, fun3d<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<3>(make_gaussian<double, 5>(), interval, 0.0, fun3d<double>) == Approx(REAL_VALUE));
    REQUIRE(integrate<3>(make_gaussian<double, 6>(), interval, 0.0, fun3d<double>) == Approx(REAL_VALUE));
  }

  SECTION("#Dimension = 3, T = float")
  {
    const auto REAL_VALUE = 577.9010f;

    auto interval = Interval<float, 3>{{ {1.0f, 2.0f}, {-0.5f, -0.25f}, {-3.5f, 7.5f} }};

    REQUIRE(integrate<3>(make_gaussian<float, 1>(), interval, 0.0f, fun3d<float>) == Approx(REAL_VALUE).margin(500)); // single point gauss is not enough to get the correct result
    REQUIRE(integrate<3>(make_gaussian<float, 2>(), interval, 0.0f, fun3d<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<3>(make_gaussian<float, 3>(), interval, 0.0f, fun3d<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<3>(make_gaussian<float, 4>(), interval, 0.0f, fun3d<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<3>(make_gaussian<float, 5>(), interval, 0.0f, fun3d<float>) == Approx(REAL_VALUE));
    REQUIRE(integrate<3>(make_gaussian<float, 6>(), interval, 0.0f, fun3d<float>) == Approx(REAL_VALUE));
  }
  
}

