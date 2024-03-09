#include <boost/test/unit_test.hpp>
#include <filesystem>

#include "Core/util.h"

BOOST_AUTO_TEST_SUITE(UtilTest)

BOOST_AUTO_TEST_CASE(HexToTupleTest) {
  std::tuple<int, int, int> aaa = HexColor::values("#3C281A");
  auto [red, green, blue] = aaa;

  BOOST_CHECK_EQUAL(red, 60);
  BOOST_CHECK_EQUAL(green, 40);
  BOOST_CHECK_EQUAL(blue, 26);
}

BOOST_AUTO_TEST_CASE(TupleToHexTest) {
  int red = 60;
  int green = 40;
  int blue = 26;

  std::string hex = "#3C281A";

  std::string result = HexColor::toStr(red, green, blue);
  std::transform(result.begin(), result.end(), result.begin(),
                 [](unsigned char c) { return std::toupper(c); });

  BOOST_CHECK_EQUAL(hex, result);
}

BOOST_AUTO_TEST_SUITE_END()