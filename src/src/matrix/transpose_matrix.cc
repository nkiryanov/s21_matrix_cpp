#include "matrix/s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::Transpose() const noexcept {
  if (this->GetRows() == 0 && this->GetColumns() == 0) {
    return S21Matrix();
  }

  S21Matrix transposed(this->GetColumns(), this->GetRows());

  for (int i = 0; i != transposed.GetRows(); ++i) {
    for (int j = 0; j != transposed.GetColumns(); ++j) {
      transposed(i, j) = (*this)(j, i);
    }
  }

  return transposed;
}

}  // namespace s21
