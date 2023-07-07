#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

using ::testing::ElementsAre;

TEST(MultiplyByNumber, MultiplyingEmptyMatrixDoNothing) {
  s21::S21Matrix matrix;

  matrix.MulNumber(10);

  EXPECT_EQ(matrix.Rows(), 0);
  EXPECT_EQ(matrix.Columns(), 0);
  EXPECT_EQ(matrix.Data().size(), 0);
}

TEST(MultiplyByNumber, MultiplyingByNumberMultiplyAllCells) {
  s21::S21Matrix matrix(4, 2, {1, 2, 3, 4, 5, 6, 7, 8});

  matrix.MulNumber(2);

  EXPECT_EQ(matrix.Rows(), 4);
  EXPECT_EQ(matrix.Columns(), 2);
  EXPECT_THAT(matrix.Data(), ElementsAre(2, 4, 6, 8, 10, 12, 14, 16));
}

TEST(MultiplyByNumber, MultiplyingByNumberOperator) {
  const s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  s21::S21Matrix result = matrix * 2;

  EXPECT_EQ(result.Rows(), 2);
  EXPECT_EQ(result.Columns(), 3);
  EXPECT_THAT(result.Data(), ElementsAre(2, 4, 6, 8, 10, 12));
}

TEST(MultiplyByNumber, MultiplyingByNumberOperatorAlsoWorks) {
  const s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  s21::S21Matrix result = 2 * matrix;

  EXPECT_EQ(result.Rows(), 2);
  EXPECT_EQ(result.Columns(), 3);
  EXPECT_THAT(result.Data(), ElementsAre(2, 4, 6, 8, 10, 12));
}

TEST(MultiplyByNumber, SelfMultiplyingByNumberOperatorWorks) {
  s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  matrix *= 2;

  EXPECT_EQ(matrix.Rows(), 2);
  EXPECT_EQ(matrix.Columns(), 3);
  EXPECT_THAT(matrix.Data(), ElementsAre(2, 4, 6, 8, 10, 12));
}

TEST(MultiplyByNumber, EmptyMatrixCouldBeMultiplied) {
  s21::S21Matrix empty_matrix;

  s21::S21Matrix result = empty_matrix * 10;

  EXPECT_TRUE(result == empty_matrix);
}
