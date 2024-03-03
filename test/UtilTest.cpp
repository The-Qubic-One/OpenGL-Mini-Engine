#include <boost/test/unit_test.hpp>

#include "Core/util.h"

BOOST_AUTO_TEST_SUITE(UtilTest)

BOOST_AUTO_TEST_CASE(UtilTest1) {

    std::tuple<int, int, int> aaa = HexColor::values("#3C281A");
    auto [red, green, blue] = aaa;

    BOOST_CHECK_EQUAL(red, 60);
    BOOST_CHECK_EQUAL(green, 40);
    BOOST_CHECK_EQUAL(blue, 26);
}

BOOST_AUTO_TEST_SUITE_END()