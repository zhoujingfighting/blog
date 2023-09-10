add_executable(
  cpp_test
  test.cpp
  first_test.cpp
)
target_link_libraries(
  cpp_test
  GTest::gtest_main
  src
)

include(GoogleTest)
gtest_discover_tests(cpp_test)