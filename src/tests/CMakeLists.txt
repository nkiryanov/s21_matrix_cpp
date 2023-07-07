include(FetchGoogleTest)
include(GoogleTest)

add_executable(
  "tests_matrix_oop"
  matrix/tests_constuctors.cpp
  matrix/tests_get_by_index_operator.cpp
  matrix/tests_eq_matrix.cpp
  matrix/tests_sum_matrix.cpp
  matrix/tests_mul_matrix.cpp
)

target_link_libraries(
  "tests_matrix_oop"
  PRIVATE gtest gmock gtest_main "s21_matrix_oop"
)

gtest_discover_tests("tests_matrix_oop")
