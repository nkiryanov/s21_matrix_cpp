cmake_minimum_required(VERSION 3.22.1)

project("MatrixOOP" VERSION 0.0.1)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED True)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Add custom cmake utils
  set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

  # Tests are only available if this is the main project
  option(PACKAGE_TESTS "Enable building the matrix class tests" ON)

  if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(tests)
  endif()

  # Set app wide compiller options
  add_compile_options(-Wall -Werror -Wextra)

  # Docs are only available if this is the main project
  find_package(Doxygen)

  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

add_subdirectory("src")
