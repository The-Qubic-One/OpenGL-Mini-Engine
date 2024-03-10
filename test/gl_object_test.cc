#include <boost/test/unit_test.hpp>

#include "opengl/gl_object.h"

BOOST_AUTO_TEST_SUITE(GLObjectTest)

class testObj : public GLObject {
 public:
  void setId(int val) { GLObject::setId(val); }
};

BOOST_AUTO_TEST_CASE(testChangeId) {
  testObj obj;
  BOOST_CHECK_EQUAL(0, obj.getId());

  obj.setId(5);
  BOOST_CHECK_EQUAL(5, obj.getId());
}

BOOST_AUTO_TEST_SUITE_END()