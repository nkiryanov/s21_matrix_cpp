#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "matrix/s21_matrix_oop.h"

TEST(MatrixEq, EmptyMatricesShouldBeEqual) {
  s21::S21Matrix first;
  s21::S21Matrix second;

  bool result = first.EqMatrix(second);

  EXPECT_TRUE(result);
}

TEST(MatrixEq, NotEqualIfRowsDiffers) {
  s21::S21Matrix first(1, 1);
  s21::S21Matrix second(2, 1);

  bool result = first.EqMatrix(second);

  EXPECT_FALSE(result);
}

TEST(MatrixEq, NotEqualIfColumnsDiffers) {
  s21::S21Matrix first(1, 1);
  s21::S21Matrix second(1, 2);

  bool result = first.EqMatrix(second);

  EXPECT_FALSE(result);
}

TEST(MatrixEq, EqualIfSameDimensionAndValues) {
  s21::S21Matrix first(2, 3, {1, 2, -10, INFINITY, 5, 6});
  s21::S21Matrix second(2, 3, {1, 2, -10, INFINITY, 5, 6});

  bool result = first.EqMatrix(second);

  EXPECT_TRUE(result);
}

TEST(MatrixEq, EqualsIfValuesDiffersButNotThanEpsilon) {
  s21::S21Matrix first(1, 1, {2.00000001});
  s21::S21Matrix second(1, 1, {2.00000003});

  bool result = first.EqMatrix(second);

  EXPECT_TRUE(result);
}

TEST(MatrixEq, FalseIfValuesDiffersMoreThanEpsilon) {
  s21::S21Matrix first(1, 1, {2.000500});
  s21::S21Matrix second(1, 1, {2.000600});

  bool result = first.EqMatrix(second);

  EXPECT_FALSE(result);
}

TEST(MatrixEq, EqOperatorReturnTrueEqualMatrices) {
  const s21::S21Matrix first(3, 1, {1.00000001, 2, 3});
  const s21::S21Matrix second(3, 1, {1.00000005, 2, 3});

  EXPECT_TRUE(first == second);
}

TEST(MatrixEq, EqOperatorReturnFalseEqualMatrices) {
  const s21::S21Matrix first(1, 1, {1});
  const s21::S21Matrix second(1, 1, {10});

  EXPECT_FALSE(first == second);
}
