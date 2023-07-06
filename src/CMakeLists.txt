cmake_minimum_required(VERSION 3.22.1)

project("MatrixOOP" VERSION 0.0.1)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED True)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Add custom cmake utils
  set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

  # Set install prefix if this is the main app
  set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/../_install_dir/")

  # Add test and coverage report targets
  option(BUILD_TESTING "Builds only the test executable." OFF)
  option(CODE_COVERAGE "Collect coverage from test library" OFF)

  if(BUILD_TESTING)
    enable_testing()
  endif()

  if(BUILD_TESTING AND ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()

    setup_target_for_coverage_gcovr_html(
      NAME "gcov_coverage_report"
      EXECUTABLE ctest
      EXCLUDE "tests/*"
    )
  endif()

  # Set app wide compiller options
  add_compile_options(-Wall -Werror -Wextra)
endif()

add_subdirectory("src")
add_subdirectory("app")

if(BUILD_TESTING AND CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  add_subdirectory(tests)
endif()