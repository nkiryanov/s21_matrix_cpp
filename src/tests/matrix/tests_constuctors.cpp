#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(MatrixConstructors, MatrixSizeCreateSquareMatrix) {
  std::vector<double> expected_values(25, 0);

  s21::S21Matrix matrix(5);

  EXPECT_EQ(matrix.Rows(), 5);
  EXPECT_EQ(matrix.Columns(), 5);
  EXPECT_EQ(matrix.Data(), expected_values);
}

TEST(MatrixConstructors, Create4x4MatrixByDefault) {
  s21::S21Matrix matrix;

  EXPECT_EQ(matrix.Rows(), 0);
  EXPECT_EQ(matrix.Columns(), 0);
}

TEST(MatrixConstructors, CreateMatrixWithRowsAndColumnsIfSet) {
  std::vector<double> expected_values(6, 0);

  s21::S21Matrix matrix(3, 2);

  EXPECT_EQ(matrix.Rows(), 3);
  EXPECT_EQ(matrix.Columns(), 2);
  EXPECT_EQ(matrix.Data(), expected_values);
}

TEST(MatrixConstructors, CreateMatrixWithPredefinedValues) {
  std::vector<double> expected_values{1, 2, 3, 4, 5, 6};

  s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  EXPECT_EQ(matrix.Rows(), 2);
  EXPECT_EQ(matrix.Columns(), 3);
  EXPECT_EQ(matrix.Data(), expected_values);
}

TEST(MatrixConstructors, CreateByCopyAssignmentWorks) {
  s21::S21Matrix matrix_to_copy(2, 1, {1, 2});

  s21::S21Matrix created_by_copy = matrix_to_copy;

  EXPECT_EQ(created_by_copy.Rows(), 2);
  EXPECT_EQ(created_by_copy.Columns(), 1);
  EXPECT_EQ(created_by_copy.Data(), matrix_to_copy.Data());
}

TEST(MatrixConstructors, CopyByAssignmentWorks) {
  s21::S21Matrix matrix_to_copy(2, 1, {1, 2});
  s21::S21Matrix existed_matrix;

  existed_matrix = matrix_to_copy;

  EXPECT_EQ(existed_matrix.Rows(), 2);
  EXPECT_EQ(existed_matrix.Columns(), 1);
  EXPECT_EQ(existed_matrix.Data(), matrix_to_copy.Data());
}

TEST(MatrixConstructors, MoveConstructorWorks) {
  s21::S21Matrix matrix_to_move(2, 1, {1, 2});

  s21::S21Matrix created_matrix(std::move(matrix_to_move));

  EXPECT_EQ(created_matrix.Rows(), 2);
  EXPECT_EQ(created_matrix.Columns(), 1);
  EXPECT_THAT(created_matrix.Data(), ::testing::ElementsAre(1, 2));
  EXPECT_EQ(matrix_to_move.Data().size(), 0);  // actually moved
}

TEST(MatrixConstructors, MoveAssignmentWorks) {
  s21::S21Matrix matrix_to_move(2, 1, {1, 2});
  s21::S21Matrix existed_matrix(1, 1, {10});

  existed_matrix = std::move(matrix_to_move);

  EXPECT_EQ(existed_matrix.Rows(), 2);
  EXPECT_EQ(existed_matrix.Columns(), 1);
  EXPECT_THAT(existed_matrix.Data(), ::testing::ElementsAre(1, 2));
  EXPECT_EQ(matrix_to_move.Data().size(), 0);  // actually moved
}

TEST(MatrixConstructors, ThrowIfRowsOrColumnsEqualsZero) {
  EXPECT_THROW(s21::S21Matrix matrix(3, 0), std::invalid_argument);
}

TEST(MatrixConstructors, ThrowIfRowsOrColumnsNegative) {
  EXPECT_THROW(s21::S21Matrix matrix(-3, 3), std::invalid_argument);
}

TEST(MatrixConstructors, ThrowIfRowsInitializerListNotMatchRowsAndColumns) {
  EXPECT_THROW(s21::S21Matrix matrix(2, 2, {1, 0}), std::invalid_argument);
}