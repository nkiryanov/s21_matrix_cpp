add_executable(
  "matrix_app"
  main.cpp
)

target_link_libraries("matrix_app" "s21_matrix_oop")

install(TARGETS "matrix_app")