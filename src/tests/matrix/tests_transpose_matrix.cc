#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

using ::testing::ElementsAre;

TEST(MatrixTranspose, EmptyMatrixTransposedToItself) {
  const s21::S21Matrix empty_matrix;

  s21::S21Matrix transposed = empty_matrix.Transpose();

  EXPECT_TRUE(transposed == empty_matrix);
}

TEST(MatrixTranspose, MatrixActuallyTransposed) {
  //           1 4   1 2 3
  // A = A^T = 2 5 = 4 5 6
  //           3 6
  const s21::S21Matrix matrix(3, 2, {1, 4, 2, 5, 3, 6});

  s21::S21Matrix transposed = matrix.Transpose();

  EXPECT_EQ(transposed.Rows(), 2);
  EXPECT_EQ(transposed.Columns(), 3);
  EXPECT_THAT(transposed.Data(), ElementsAre(1, 2, 3, 4, 5, 6));
}
