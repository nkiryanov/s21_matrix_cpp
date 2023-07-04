include(FetchGoogleTest)
include(GoogleTest)

add_executable(
  "tests_matrix_oop"
  matrix/tests_constuctors.cpp
)

target_link_libraries(
  "tests_matrix_oop"
  PRIVATE gtest gtest_main "s21_matrix_oop"
)

gtest_discover_tests("tests_matrix_oop")
