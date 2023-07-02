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

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
)
