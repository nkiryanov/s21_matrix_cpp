#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "matrix/s21_matrix_oop.h"

using ::testing::ElementsAre;

TEST(MultiplyByNumber, MultiplyingEmptyMatrixDoNothing) {
  s21::S21Matrix matrix;

  matrix.MulNumber(10);

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetColumns(), 0);
  EXPECT_EQ(matrix.GetData().size(), 0);
}

TEST(MultiplyByNumber, MultiplyingByNumberMultiplyAllCells) {
  s21::S21Matrix matrix(4, 2, {1, 2, 3, 4, 5, 6, 7, 8});

  matrix.MulNumber(2);

  EXPECT_EQ(matrix.GetRows(), 4);
  EXPECT_EQ(matrix.GetColumns(), 2);
  EXPECT_THAT(matrix.GetData(), ElementsAre(2, 4, 6, 8, 10, 12, 14, 16));
}

TEST(MultiplyByNumber, MultiplyingByNumberOperator) {
  const s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  s21::S21Matrix result = matrix * 2;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetColumns(), 3);
  EXPECT_THAT(result.GetData(), ElementsAre(2, 4, 6, 8, 10, 12));
}

TEST(MultiplyByNumber, MultiplyingByNumberOperatorAlsoWorks) {
  const s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  s21::S21Matrix result = 2 * matrix;

  EXPECT_EQ(result.GetRows(), 2);
  EXPECT_EQ(result.GetColumns(), 3);
  EXPECT_THAT(result.GetData(), ElementsAre(2, 4, 6, 8, 10, 12));
}

TEST(MultiplyByNumber, SelfMultiplyingByNumberOperatorWorks) {
  s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  matrix *= 2;

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetColumns(), 3);
  EXPECT_THAT(matrix.GetData(), ElementsAre(2, 4, 6, 8, 10, 12));
}

TEST(MultiplyByNumber, EmptyMatrixCouldBeMultiplied) {
  s21::S21Matrix empty_matrix;

  s21::S21Matrix result = empty_matrix * 10;

  EXPECT_TRUE(result == empty_matrix);
}
