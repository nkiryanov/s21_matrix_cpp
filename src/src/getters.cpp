#include "s21_matrix_oop.h"

namespace s21 {

int S21Matrix::Rows() const { return rows_; }

int S21Matrix::Columns() const { return columns_; }

std::vector<double>& S21Matrix::Data() { return matrix_; }
const std::vector<double>& S21Matrix::Data() const { return matrix_; }

}  // namespace s21