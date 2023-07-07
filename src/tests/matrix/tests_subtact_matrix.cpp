#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(SubtractMatrix, SubtractingEmptyMatricesDoNothing) {
  s21::S21Matrix first_empty;
  const s21::S21Matrix second_empty;

  first_empty.SubMatrix(second_empty);

  EXPECT_TRUE(first_empty == second_empty);
}

TEST(SubtractMatrix, ActuallySubtractingMatrices) {
  s21::S21Matrix first(2, 3, {1, 2, 3, 4, 5, 6});
  const s21::S21Matrix second(2, 3, {1, 2, 3, 4, 5, 6});

  first.SubMatrix(second);

  EXPECT_TRUE(first == s21::S21Matrix(2, 3));
}

TEST(SubtractMatrix, ThrowIfRowsNotMatch) {
  s21::S21Matrix first(3, 2, {1, 2, 3, 4, 5, 6});
  const s21::S21Matrix second(1, 2, {1, 2});

  EXPECT_THROW(first.SubMatrix(second), std::invalid_argument);
}

TEST(SubtractMatrix, ThrowIfColumnsNotMatch) {
  s21::S21Matrix first(3, 2, {1, 2, 3, 4, 5, 6});
  const s21::S21Matrix second(3, 1, {1, 2, 3});

  EXPECT_THROW(first.SubMatrix(second), std::invalid_argument);
}

TEST(SubtractMatrix, SubtractingMatrixOperatorWorksOk) {
  const s21::S21Matrix first(1, 2, {1, 2});
  const s21::S21Matrix second(1, 2, {1, 2});
  const s21::S21Matrix expected(1, 2);

  s21::S21Matrix result = first - second;

  EXPECT_TRUE(result == expected);
}

TEST(SubtractMatrix, SubtractingSelfMatrixOperatorWorksOk) {
  s21::S21Matrix matrix(1, 2, {1, 2});
  const s21::S21Matrix second(1, 2, {1, 2});
  const s21::S21Matrix expected(1, 2);

  matrix -= second;

  EXPECT_TRUE(matrix == expected);
}
