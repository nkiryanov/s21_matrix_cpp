#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <vector>

namespace s21 {

class S21Matrix {
 private:
  int rows_;
  int columns_;
  std::vector<double> matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows);
  S21Matrix(int rows, int columns);
  S21Matrix(int rows, int columns, std::initializer_list<double> values);

  int Rows();
  int Columns();
  std::vector<double>& Data();
};

}  // namespace s21

#endif  // S21_MATRIX_OOP_H_
