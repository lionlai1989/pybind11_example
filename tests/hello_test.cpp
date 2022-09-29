#include "Student.h"
#include "my_eigen.h"
#include <Eigen/Dense>
#include <gtest/gtest.h>
#include <iostream>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, MatrixAssertions) {
  // Test cross matrix creation.
  Eigen::Matrix<float, 3, 1> v;
  v << 1, 2, 3;
  auto ret_v = crossMatrix(v);
  Eigen::Matrix<float, 3, 3> expected_v;
  // expected_v:
  //  0 -3  2
  //  3  0 -1
  // -2  1  0
  expected_v << 0, -3, 2, 3, 0, -1, -2, 1, 0;

  EXPECT_EQ(expected_v, ret_v);
}

TEST(HelloTest, ClassAssertion) {
  Student s("Joe");
  s.display();
  std::cout << s.get_name() << std::endl;

  EXPECT_EQ(s.get_name(), "Joe");
}
