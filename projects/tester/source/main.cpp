#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <quadrature\Gaussian.h>

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

TEST_CASE("quadrature::integrate with Gauss in range(-1, 1)", "[integrate]") 
{
  SECTION("#Dimension = 1, T = double")
  {   
    const auto REAL_VALUE = 11 + 1.0 / 3.0;

    REQUIRE(quadrature::integrate<1>(make_gaussian<double, 1>(), 0.0, fun<double>) == Approx(REAL_VALUE).margin(1.5)); // single point gauss is not enough to get the correct result
    REQUIRE(quadrature::integrate<1>(make_gaussian<double, 2>(), 0.0, fun<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<1>(make_gaussian<double, 3>(), 0.0, fun<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<1>(make_gaussian<double, 4>(), 0.0, fun<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<1>(make_gaussian<double, 5>(), 0.0, fun<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<1>(make_gaussian<double, 6>(), 0.0, fun<double>) == Approx(REAL_VALUE));
  }
  
  SECTION("#Dimension = 1, T = float")
  {
    const auto REAL_VALUE = 11 + 1.0f / 3.0f;

    REQUIRE(quadrature::integrate<1>(make_gaussian<float, 1>(), 0.0f, fun<float>) == Approx(REAL_VALUE).margin(1.5f)); // single point gauss is not enough to get the correct result
    REQUIRE(quadrature::integrate<1>(make_gaussian<float, 2>(), 0.0f, fun<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<1>(make_gaussian<float, 3>(), 0.0f, fun<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<1>(make_gaussian<float, 4>(), 0.0f, fun<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<1>(make_gaussian<float, 5>(), 0.0f, fun<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<1>(make_gaussian<float, 6>(), 0.0f, fun<float>) == Approx(REAL_VALUE));
  }

  SECTION("#Dimension = 2, T = double")
  {
    const auto REAL_VALUE = 13 + 1.0 / 3.0;

    REQUIRE(quadrature::integrate<2>(make_gaussian<double, 1>(), 0.0, fun2d<double>) == Approx(REAL_VALUE).margin(1.5)); // single point gauss is not enough to get the correct result
    REQUIRE(quadrature::integrate<2>(make_gaussian<double, 2>(), 0.0, fun2d<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<2>(make_gaussian<double, 3>(), 0.0, fun2d<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<2>(make_gaussian<double, 4>(), 0.0, fun2d<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<2>(make_gaussian<double, 5>(), 0.0, fun2d<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<2>(make_gaussian<double, 6>(), 0.0, fun2d<double>) == Approx(REAL_VALUE));
  }

  SECTION("#Dimension = 2, T = float")
  {
    const auto REAL_VALUE = 13 + 1.0f / 3.0f;

    REQUIRE(quadrature::integrate<2>(make_gaussian<float, 1>(), 0.0f, fun2d<float>) == Approx(REAL_VALUE).margin(1.5)); // single point gauss is not enough to get the correct result
    REQUIRE(quadrature::integrate<2>(make_gaussian<float, 2>(), 0.0f, fun2d<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<2>(make_gaussian<float, 3>(), 0.0f, fun2d<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<2>(make_gaussian<float, 4>(), 0.0f, fun2d<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<2>(make_gaussian<float, 5>(), 0.0f, fun2d<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<2>(make_gaussian<float, 6>(), 0.0f, fun2d<float>) == Approx(REAL_VALUE));
  }

  SECTION("#Dimension = 3, T = double")
  {
    const auto REAL_VALUE = 26 + 2.0 / 3.0;

    REQUIRE(quadrature::integrate<3>(make_gaussian<double, 1>(), 0.0, fun3d<double>) == Approx(REAL_VALUE).margin(3)); // single point gauss is not enough to get the correct result
    REQUIRE(quadrature::integrate<3>(make_gaussian<double, 2>(), 0.0, fun3d<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<3>(make_gaussian<double, 3>(), 0.0, fun3d<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<3>(make_gaussian<double, 4>(), 0.0, fun3d<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<3>(make_gaussian<double, 5>(), 0.0, fun3d<double>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<3>(make_gaussian<double, 6>(), 0.0, fun3d<double>) == Approx(REAL_VALUE));
  }

  SECTION("#Dimension = 3, T = float")
  {
    const auto REAL_VALUE = 26 + 2.0f / 3.0f;

    REQUIRE(quadrature::integrate<3>(make_gaussian<float, 1>(), 0.0f, fun3d<float>) == Approx(REAL_VALUE).margin(3)); // single point gauss is not enough to get the correct result
    REQUIRE(quadrature::integrate<3>(make_gaussian<float, 2>(), 0.0f, fun3d<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<3>(make_gaussian<float, 3>(), 0.0f, fun3d<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<3>(make_gaussian<float, 4>(), 0.0f, fun3d<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<3>(make_gaussian<float, 5>(), 0.0f, fun3d<float>) == Approx(REAL_VALUE));
    REQUIRE(quadrature::integrate<3>(make_gaussian<float, 6>(), 0.0f, fun3d<float>) == Approx(REAL_VALUE));
  }
  
}

