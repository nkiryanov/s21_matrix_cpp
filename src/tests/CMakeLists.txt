include(FetchGoogleTest)
include(GoogleTest)

add_executable(
  "tests_matrix_oop"
  matrix/tests_constuctors.cc
  matrix/tests_getters.cc
  matrix/tests_setters.cc
  matrix/tests_operator_get_by_index.cc
  matrix/tests_eq_matrix.cc
  matrix/tests_sum_matrix.cc
  matrix/tests_subtact_matrix.cc
  matrix/tests_multiply_number.cc
  matrix/tests_multiply_matrix.cc
  matrix/tests_transpose_matrix.cc
  matrix/tests_minor_matrix.cc
  matrix/tests_determinant_matrix.cc
  matrix/tests_calc_complements_matrix.cc
  matrix/tests_inverse_matrix.cc
)

target_link_libraries(
  "tests_matrix_oop"
  PRIVATE gtest gmock gtest_main "s21_matrix_oop"
)

gtest_discover_tests("tests_matrix_oop")
