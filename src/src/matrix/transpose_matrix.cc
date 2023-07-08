#include "matrix/s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::Transpose() const noexcept {
  if (this->Rows() == 0 && this->Columns() == 0) {
    return S21Matrix();
  }

  S21Matrix transposed(this->Columns(), this->Rows());

  for (int i = 0; i != transposed.Rows(); ++i) {
    for (int j = 0; j != transposed.Columns(); ++j) {
      transposed(i, j) = (*this)(j, i);
    }
  }

  return transposed;
}

}  // namespace s21
