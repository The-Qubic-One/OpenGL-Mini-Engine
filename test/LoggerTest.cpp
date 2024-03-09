#include <boost/test/unit_test.hpp>

#include "Core/Logger.h"

BOOST_AUTO_TEST_SUITE(LoggerTest)

BOOST_AUTO_TEST_CASE(LoggerTest1) {
  Logger logger;

  BOOST_CHECK(logger.empty());
}

BOOST_AUTO_TEST_SUITE_END()