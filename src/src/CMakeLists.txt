file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${MatrixOOP_SOURCE_DIR}/include/*.h")

add_library(
  "s21_matrix_oop"
  s21_matrix_oop.cc
  getters.cc
  constructors.cc
  get_by_index_operator.cc
  equal_matrix.cc
  sum_matrix.cc
  subtract_matrix.cc
  multiply_number.cc
  multiply_matrix.cc
  transpose_matrix.cc
  minor_matrix.cc
  determinant_matrix.cc
  calc_complements_matrix.cc
  inverse_matrix.cc
  ${HEADER_LIST}
)

target_include_directories(
  "s21_matrix_oop"
  PUBLIC ../include
)
