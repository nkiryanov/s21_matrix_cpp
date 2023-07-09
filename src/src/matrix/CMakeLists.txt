file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${MatrixOOP_SOURCE_DIR}/include/matrix/*.h")

add_library(
  "s21_matrix_oop"
  s21_matrix_oop.cc
  setters.cc
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
  PUBLIC ../../include
)

target_sources("s21_matrix_oop" PUBLIC
    FILE_SET public_headers
    TYPE HEADERS
    BASE_DIRS ../../include
    FILES ../../include/matrix/s21_matrix_oop.h
  )

install(TARGETS "s21_matrix_oop" FILE_SET public_headers 
  LIBRARY DESTINATION .
)
