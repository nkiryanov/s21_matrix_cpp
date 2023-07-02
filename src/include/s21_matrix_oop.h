#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

namespace s21 {

class S21Matrix {
 private:
  int rows_;
  int columns_;
  double *matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows);
  S21Matrix(int rows, int columns);

  int Rows();
  int Columns();
};

}  // namespace s21

#endif  // S21_MATRIX_OOP_H_
