#include <algorithm>
#include <stdexcept>

#include "matrix/s21_matrix_oop.h"

namespace s21 {
void S21Matrix::SetRows(int desired_rows) {
  // Edge cases
  if (desired_rows == this->GetRows()) return;

  if (desired_rows < 0) {
    throw std::length_error("The number or rows couldn't be less than zero");
  }

  S21Matrix resized_matrix(desired_rows, this->GetColumns());

  int rows_index_to_copy = std::min(this->GetRows(), desired_rows);

  for (int i = 0; i != rows_index_to_copy; ++i) {
    for (int j = 0; j != this->GetColumns(); ++j) {
      resized_matrix(i, j) = (*this)(i, j);
    }
  }

  std::swap(*this, resized_matrix);
}

void S21Matrix::SetColumns(int desired_columns) {
  // Edge cases
  if (desired_columns == this->GetColumns()) return;

  if (desired_columns <= 0) {
    throw std::length_error("The number or columns couldn't be less than zero");
  }

  S21Matrix resized_matrix(this->GetRows(), desired_columns);

  int columns_index_to_copy = std::min(this->GetColumns(), desired_columns);

  for (int i = 0; i != this->GetRows(); ++i) {
    for (int j = 0; j != columns_index_to_copy; ++j) {
      resized_matrix(i, j) = (*this)(i, j);
    }
  }

  std::swap(*this, resized_matrix);
}

}  // namespace s21
