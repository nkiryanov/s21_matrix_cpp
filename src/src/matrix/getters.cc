#include "matrix/s21_matrix_oop.h"

namespace s21 {

int S21Matrix::Rows() const noexcept { return rows_; }

int S21Matrix::Columns() const noexcept { return columns_; }

const std::vector<double>& S21Matrix::Data() const noexcept { return matrix_; }

double S21Matrix::Epsilon() const noexcept { return epsilon_; }

}  // namespace s21
