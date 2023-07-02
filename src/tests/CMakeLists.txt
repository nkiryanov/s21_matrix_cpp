include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0  # release-1.13.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

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
