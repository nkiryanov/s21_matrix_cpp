#include <stdexcept>

#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(MatrixConstructors, MatrixSizeCreateSquareMatrix) {
  s21::S21Matrix matrix(5);

  EXPECT_EQ(matrix.Rows(), 5);
  EXPECT_EQ(matrix.Columns(), 5);
}

TEST(MatrixConstructors, Create4x4MatrixByDefault) {
  s21::S21Matrix matrix;

  EXPECT_EQ(matrix.Rows(), 4);
  EXPECT_EQ(matrix.Columns(), 4);
}

TEST(MatrixConstructors, CreateMatrixWithRowsAndColumnsIfSet) {
  s21::S21Matrix matrix(3, 2);

  EXPECT_EQ(matrix.Rows(), 3);
  EXPECT_EQ(matrix.Columns(), 2);
}

TEST(MatrixConstructors, ExceptionIfRowsOrColumnsNotValid) {
  EXPECT_THROW(s21::S21Matrix matrix(3, 0), std::invalid_argument);
}
