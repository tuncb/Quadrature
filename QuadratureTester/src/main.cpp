#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <quadrature\Gaussian.h>

TEST_CASE("quadrature::integrate with Gauss", "[integrate]") 
{
  auto compute_pos = [](double x) { return x + 1.0; };

  SECTION("#Dimension = 1, #Integration Points = 1")
  {
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<1>, 1>([&](double ip1, double w1) {
      sum += compute_pos(ip1) * w1;
    });
    REQUIRE(sum == Approx(2.0));
  }

  SECTION("Dimension = 2, #Integration Points = 1")
  {
    const unsigned int ndim = 2;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<1>, ndim>([&](double ip1, double ip2, double w1, double w2) {
      sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
    });
    REQUIRE(sum == Approx(4.0));
  }
  
  SECTION("Dimension = 3, #Integration Points = 1")
  {
    const unsigned int ndim = 3;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<1>, ndim>([&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
      sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
    });
    REQUIRE(sum == Approx(8.0));
  }

  SECTION("Dimension = 1, #Integration Points = 2")
  {
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<2>, 1>([&](double ip1, double w1) {
      sum += compute_pos(ip1) * w1;
    });
    REQUIRE(sum == Approx(2.0));
  }

  SECTION("Dimension = 2, #Integration Points = 2")
  {
    const unsigned int ndim = 2;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<2>, ndim>([&](double ip1, double ip2, double w1, double w2) {
      sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
    });
    REQUIRE(sum == Approx(4.0));
  }

  SECTION("Dimension = 3, #Integration Points = 2")
  {
    const unsigned int ndim = 3;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<2>, ndim>([&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
      sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
    });
    REQUIRE(sum == Approx(8.0));
  }

  SECTION("Dimension = 1, #Integration Points = 3")
  {
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<3>, 1>([&](double ip1, double w1) {
      sum += compute_pos(ip1) * w1;
    });
    REQUIRE(sum == Approx(2.0));
  }

  SECTION("Dimension = 2, #Integration Points = 3")
  {
    const unsigned int ndim = 2;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<3>, ndim>([&](double ip1, double ip2, double w1, double w2) {
      sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
    });
    REQUIRE(sum == Approx(4.0));
  }

  SECTION("Dimension = 3, #Integration Points = 3")
  {
    const unsigned int ndim = 3;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<3>, ndim>([&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
      sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
    });
    REQUIRE(sum == Approx(8.0));
  }

  SECTION("Dimension = 1, #Integration Points = 4")
  {
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<4>, 1>([&](double ip1, double w1) {
      sum += compute_pos(ip1) * w1;
    });
    REQUIRE(sum == Approx(2.0));
  }

  SECTION("Dimension = 2, #Integration Points = 4")
  {
    const unsigned int ndim = 2;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<4>, ndim>([&](double ip1, double ip2, double w1, double w2) {
      sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
    });
    REQUIRE(sum == Approx(4.0));
  }

  SECTION("Dimension = 3, #Integration Points = 4")
  {
    const unsigned int ndim = 3;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<4>, ndim>([&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
      sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
    });
    REQUIRE(sum == Approx(8.0));
  }

  SECTION("Dimension = 1, #Integration Points = 5")
  {
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<5>, 1>([&](double ip1, double w1) {
      sum += compute_pos(ip1) * w1;
    });
    REQUIRE(sum == Approx(2.0));
  }

  SECTION("Dimension = 2, #Integration Points = 5")
  {
    const unsigned int ndim = 2;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<5>, ndim>([&](double ip1, double ip2, double w1, double w2) {
      sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
    });
    REQUIRE(sum == Approx(4.0));
  }

  SECTION("Dimension = 3, #Integration Points = 5")
  {
    const unsigned int ndim = 3;
    double sum = 0.0;
    quadrature::integrate<quadrature::Gaussian<5>, ndim>([&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
      sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
    });
    REQUIRE(sum == Approx(8.0));
  }


  SECTION("Dimension = 1, #Integration Points = 6")
  {
    double sum = 0.0;
    auto q = quadrature::Gaussian<6>();
    quadrature::integrate<1>(q, [&](double ip1, double w1) {
      sum += compute_pos(ip1) * w1;
    });
    REQUIRE(sum == Approx(2.0));
  }

  SECTION("Dimension = 2, #Integration Points = 6")
  {
    const unsigned int ndim = 2;
    double sum = 0.0;
    auto q = quadrature::Gaussian<6>();
    quadrature::integrate<ndim>(q, [&](double ip1, double ip2, double w1, double w2) {
      sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
    });
    REQUIRE(sum == Approx(4.0));
  }

  SECTION("Dimension = 3, #Integration Points = 6")
  {
    const unsigned int ndim = 3;
    double sum = 0.0;
    auto q = quadrature::Gaussian<6>();
    quadrature::integrate<ndim>(q, [&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
      sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
    });
    REQUIRE(sum == Approx(8.0));
  }
}