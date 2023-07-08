include(FetchGoogleTest)
include(GoogleTest)

add_executable(
  "tests_matrix_oop"
  tests_constuctors.cc
  tests_getters.cc
  tests_setters.cc
  tests_operator_get_by_index.cc
  tests_eq_matrix.cc
  tests_sum_matrix.cc
  tests_subtact_matrix.cc
  tests_multiply_number.cc
  tests_multiply_matrix.cc
  tests_transpose_matrix.cc
  tests_minor_matrix.cc
  tests_determinant_matrix.cc
  tests_calc_complements_matrix.cc
  tests_inverse_matrix.cc
)

target_link_libraries(
  "tests_matrix_oop"
  PRIVATE gtest gmock gtest_main "s21_matrix_oop"
)

gtest_discover_tests("tests_matrix_oop")
