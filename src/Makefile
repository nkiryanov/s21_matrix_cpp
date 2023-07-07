CMAKE_ROOT := .

BUILD_TESTING := ON
ENABLE_COVERAGE := OFF
CMAKE_BUILD_TYPE := Debug

BUILD_DIR_ROOT := $(CMAKE_ROOT)/../build
BUILD_DIR = $(BUILD_DIR_ROOT)/$(CMAKE_BUILD_TYPE)
INSTALL_DIR = $(CMAKE_ROOT)/../_install_dir

# Hardocoded test exec
# This defenitly should be changed to use "ctest -T memcheck" instead, but didn't
# find an easy way how to do that
HARDCODED_TEST_EXEX = $(BUILD_DIR)/tests/tests_matrix_oop

SRC := $(shell find $(CMAKE_ROOT) -name "*.c" -o -name "*.cpp" -o -name "*.cc")
HEADERS := $(shell find $(CMAKE_ROOT) -name "*.h" -o -name "*.hpp")

.PHONY: all lint fmt build test tests intstall gcov_report echo clean s21_matrix_oop.a

all: install

lint:
	@clang-format --style=Google --Werror --dry-run $(SRC) $(HEADERS) && echo "Clagn-format passed"
	@cppcheck $(SRC) $(HEADERS) --language=c++

fmt:
	@clang-format --style=Google --Werror -i $(SRC) $(HEADERS) && echo "Formatted"

build:
	cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) -DBUILD_TESTING=$(BUILD_TESTING) -DENABLE_COVERAGE=$(ENABLE_COVERAGE)
	cmake --build $(BUILD_DIR)

test: tests
tests: build
	ctest --output-on-failure --test-dir $(BUILD_DIR)

valgrind_tests: build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-exitcode=1 $(HARDCODED_TEST_EXEX)

coverage_html_report: ENABLE_COVERAGE = ON
coverage_html_report: build
	cmake --build $(BUILD_DIR) --target coverage_report

gcov_report: coverage_html_report
	open $(BUILD_DIR)/gcov_coverage_report/index.html

s21_matrix_oop.a: install 

install: BUILD_TESTING = OFF
install: CMAKE_BUILD_TYPE = Release
install: build
	cmake --install $(BUILD_DIR)

uninstall:
	rm -rf $(INSTALL_DIR)

echo:
	@echo "HEADERS = $(HEADERS)"
	@echo "SRC = $(SRC)"

clean: uninstall
	rm -rf $(BUILD_DIR_ROOT) 
