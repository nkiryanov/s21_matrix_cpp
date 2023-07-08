#include <initializer_list>
#include <stdexcept>

#include "matrix/s21_matrix_oop.h"

namespace s21 {

static int VerifyRange(int matrix_dimension) {
  if (matrix_dimension < 0) {
    throw std::invalid_argument("Row or colons must be not negative");
  }

  return matrix_dimension;
}

static const std::initializer_list<double>& VerifyInitializerList(
    int rows, int columns, const std::initializer_list<double>& matrix_values) {
  if (static_cast<size_t>(rows * columns) != matrix_values.size()) {
    throw std::invalid_argument("Provided values not match the matrix size");
  }

  return matrix_values;
}

static const std::vector<double> VerifyListOfInitializerLists(
    int rows, int columns,
    const std::initializer_list<std::initializer_list<double>>& rows_list) {
  if (static_cast<size_t>(rows) != rows_list.size()) {
    throw std::invalid_argument(
        "The initializer list doesn't match the number of rows of the matrix.");
  }

  for (const auto& row_values : rows_list) {
    if (static_cast<size_t>(columns) != row_values.size()) {
      throw std::invalid_argument(
          "The size of initializer lists must match to the number of matrix "
          "columns.");
    }
  }

  std::vector<double> concatenated_rows;
  concatenated_rows.reserve(rows * columns);

  for (const auto& row_values : rows_list) {
    concatenated_rows.insert(concatenated_rows.end(), row_values.begin(),
                             row_values.end());
  }

  return concatenated_rows;
}

S21Matrix::S21Matrix() : rows_(0), columns_(0), matrix_(0) {}

S21Matrix::S21Matrix(int rows, int columns)
    : rows_(VerifyRange(rows)),
      columns_(VerifyRange(columns)),
      matrix_(rows * columns, 0) {}

S21Matrix::S21Matrix(int size) : S21Matrix(size, size) {}

S21Matrix::S21Matrix(int rows, int columns,
                     std::initializer_list<double> matrix_values)
    : rows_(VerifyRange(rows)),
      columns_(VerifyRange(columns)),
      matrix_(VerifyInitializerList(rows, columns, matrix_values)) {}

S21Matrix::S21Matrix(
    int rows, int columns,
    std::initializer_list<std::initializer_list<double>> rows_list)
    : rows_(VerifyRange(rows)),
      columns_(VerifyRange(columns)),
      matrix_(VerifyListOfInitializerLists(rows, columns, rows_list)) {}

}  // namespace s21
