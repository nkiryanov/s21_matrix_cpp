file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${MatrixOOP_SOURCE_DIR}/include/*.h")

add_library(
  "s21_matrix_oop"
  s21_matrix_oop.cpp
  ${HEADER_LIST}
)

target_include_directories(
  "s21_matrix_oop"
  PUBLIC ../include
)
