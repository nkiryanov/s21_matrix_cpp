include(FetchGoogleTest)
include(GoogleTest)

add_executable(
  "tests_matrix_oop"
  matrix/tests_constuctors.cpp
  matrix/tests_getters.cpp
  matrix/tests_operator_get_by_index.cpp
  matrix/tests_eq_matrix.cpp
  matrix/tests_sum_matrix.cpp
  matrix/tests_subtact_matrix.cpp
  matrix/tests_multiply_number.cpp
  matrix/tests_multiply_matrix.cpp
)

target_link_libraries(
  "tests_matrix_oop"
  PRIVATE gtest gmock gtest_main "s21_matrix_oop"
)

gtest_discover_tests("tests_matrix_oop")
