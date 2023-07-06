CMAKE_ROOT := .

BUILD_TESTING := ON
ENABLE_COVERAGE := OFF
CMAKE_BUILD_TYPE := Debug

BUILD_DIR = $(CMAKE_ROOT)/../build/$(CMAKE_BUILD_TYPE)/
INSTALL_DIR = $(CMAKE_ROOT)/../_install_dir/

SRC := $(shell find $(CMAKE_ROOT) -name "*.c" -o -name "*.cpp")
HEADERS := $(shell find $(CMAKE_ROOT) -name "*.h" -o -name "*.hpp")

.PHONY: all lint fmt build test tests intstall gcov_report echo clean

all: install

lint:
	@clang-format --style=Google --Werror --dry-run $(SRC) $(HEADERS) && echo "Clagn-format passed"
	@cppcheck $(SRC) $(HEADERS)

fmt:
	@clang-format --style=Google --Werror -i $(SRC) $(HEADERS) && echo "Formatted"

build:
	cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) -DBUILD_TESTING=$(BUILD_TESTING) -DENABLE_COVERAGE=$(ENABLE_COVERAGE)
	cmake --build $(BUILD_DIR)

test: tests
tests: build
	ctest --output-on-failure --test-dir $(BUILD_DIR)

gcov_report: ENABLE_COVERAGE = ON
gcov_report: build
	cmake --build $(BUILD_DIR) --target gcov_coverage_report

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
	rm -rf $(BUILD_DIR) 
