#define BOOST_TEST_MODULE Quadrature

#include <boost/test/unit_test.hpp>
#include <quadrature\quadrature.h>
#include <quadrature\Gaussian.h>


double compute_pos(double x) { return x + 1.0;}

BOOST_AUTO_TEST_SUITE(gauss)

BOOST_AUTO_TEST_CASE(gauss_1_1)
{
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<1>, 1>([&](double ip1, double w1) {
    sum += compute_pos(ip1) * w1;
  });
  BOOST_CHECK_CLOSE( sum, 2.0, 0.00000001);
}

BOOST_AUTO_TEST_CASE(gauss_1_2)
{
  const unsigned int ndim = 2;
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<1>, ndim>([&](double ip1, double ip2, double w1, double w2) {
    sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
  });
  BOOST_CHECK_CLOSE( sum, 4.0, 0.00000001);
}

BOOST_AUTO_TEST_CASE(gauss_1_3)
{
  const unsigned int ndim = 3;
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<1>, ndim>([&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
    sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
  });
  BOOST_CHECK_CLOSE( sum, 8.0, 0.00000001);
}

BOOST_AUTO_TEST_CASE(gauss_2_1)
{
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<2>, 1>([&](double ip1, double w1) {
    sum += compute_pos(ip1) * w1;
  });
  BOOST_CHECK_CLOSE( sum, 2.0, 0.00000001);
}

BOOST_AUTO_TEST_CASE(gauss_2_2)
{
  const unsigned int ndim = 2;
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<2>, ndim>([&](double ip1, double ip2, double w1, double w2) {
    sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
  });
  BOOST_CHECK_CLOSE( sum, 4.0, 0.00000001);
}

BOOST_AUTO_TEST_CASE(gauss_2_3)
{
  const unsigned int ndim = 3;
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<2>, ndim>([&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
    sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
  });
  BOOST_CHECK_CLOSE( sum, 8.0, 0.00000001);
}

BOOST_AUTO_TEST_CASE(gauss_3_1)
{
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<3>, 1>([&](double ip1, double w1) {
    sum += compute_pos(ip1) * w1;
  });
  BOOST_CHECK_CLOSE( sum, 2.0, 0.00000001);
}

BOOST_AUTO_TEST_CASE(gauss_3_2)
{
  const unsigned int ndim = 2;
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<3>, ndim>([&](double ip1, double ip2, double w1, double w2) {
    sum += compute_pos(ip1) * compute_pos(ip2) * w1 * w2;
  });
  BOOST_CHECK_CLOSE( sum, 4.0, 0.00000001);
}

BOOST_AUTO_TEST_CASE(gauss_3_3)
{
  const unsigned int ndim = 3;
  double sum = 0.0;
  ozp::quadrature::integrate<ozp::quadrature::Gaussian<3>, ndim>([&](double ip1, double ip2, double ip3, double w1, double w2, double w3) {
    sum += compute_pos(ip1) * compute_pos(ip2) * compute_pos(ip3) * w1 * w2 * w3;
  });
  BOOST_CHECK_CLOSE( sum, 8.0, 0.00000001);
}



BOOST_AUTO_TEST_SUITE_END()