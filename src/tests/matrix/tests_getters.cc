#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "matrix/s21_matrix_oop.h"

TEST(MatrixGetters, RowsReturnRows) {
  const s21::S21Matrix matrix(2, 3);

  EXPECT_EQ(matrix.GetRows(), 2);
}

TEST(MatrixGetters, ColumnsReturnColumns) {
  const s21::S21Matrix matrix(2, 3);

  EXPECT_EQ(matrix.GetColumns(), 3);
}

TEST(MatrixGetters, EpsilonReturnClassStaticEpsilon) {
  const s21::S21Matrix matrix(2, 3);

  EXPECT_EQ(matrix.Epsilon(), 10e-7);
}
