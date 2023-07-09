#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "matrix/s21_matrix_oop.h"

using ::testing::ElementsAre;

TEST(MatrixConstructors, MatrixSizeCreateSquareMatrix) {
  std::vector<double> expected_values(25, 0);

  s21::S21Matrix matrix(5);

  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix.GetColumns(), 5);
  EXPECT_EQ(matrix.GetData(), expected_values);
}

TEST(MatrixConstructors, CreatedEmptyMatrixByDefault) {
  s21::S21Matrix matrix;

  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetColumns(), 0);
  EXPECT_EQ(matrix.GetData().size(), 0);
}

TEST(MatrixConstructors, CreatedEmptyMatrixIfAnyOfDimensionEqualZero) {
  s21::S21Matrix matrix(5, 0);

  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix.GetColumns(), 0);
  EXPECT_EQ(matrix.GetData().size(), 0);
}

TEST(MatrixConstructors, CreateMatrixWithRowsAndColumnsIfSet) {
  std::vector<double> expected_values(6, 0);

  s21::S21Matrix matrix(3, 2);

  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetColumns(), 2);
  EXPECT_EQ(matrix.GetData(), expected_values);
}

TEST(MatrixConstructors, CreateMatrixWithPredefinedValuesInOneList) {
  s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetColumns(), 3);
  EXPECT_THAT(matrix.GetData(), ElementsAre(1, 2, 3, 4, 5, 6));
}

TEST(MatrixConstructors, CreateMatrixWithPredefinedValuesInListOfLists) {
  s21::S21Matrix matrix(2, 3,
                        {
                            {1, 2, 3},
                            {4, 5, 6},
                        });

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetColumns(), 3);
  EXPECT_THAT(matrix.GetData(), ElementsAre(1, 2, 3, 4, 5, 6));
}

TEST(MatrixConstructors, CreateByCopyAssignmentWorks) {
  s21::S21Matrix matrix_to_copy(2, 1, {1, 2});

  s21::S21Matrix created_by_copy = matrix_to_copy;

  EXPECT_EQ(created_by_copy.GetRows(), 2);
  EXPECT_EQ(created_by_copy.GetColumns(), 1);
  EXPECT_EQ(created_by_copy.GetData(), matrix_to_copy.GetData());
}

TEST(MatrixConstructors, CopyByAssignmentWorks) {
  s21::S21Matrix matrix_to_copy(2, 1, {1, 2});
  s21::S21Matrix existed_matrix;

  existed_matrix = matrix_to_copy;

  EXPECT_EQ(existed_matrix.GetRows(), 2);
  EXPECT_EQ(existed_matrix.GetColumns(), 1);
  EXPECT_EQ(existed_matrix.GetData(), matrix_to_copy.GetData());
}

TEST(MatrixConstructors, MoveConstructorWorks) {
  s21::S21Matrix matrix_to_move(2, 1, {1, 2});

  s21::S21Matrix created_matrix(std::move(matrix_to_move));

  EXPECT_EQ(created_matrix.GetRows(), 2);
  EXPECT_EQ(created_matrix.GetColumns(), 1);
  EXPECT_THAT(created_matrix.GetData(), ElementsAre(1, 2));
  EXPECT_EQ(matrix_to_move.GetData().size(), 0);  // actually moved
}

TEST(MatrixConstructors, MoveAssignmentWorks) {
  s21::S21Matrix matrix_to_move(2, 1, {1, 2});
  s21::S21Matrix existed_matrix(1, 1, {10});

  existed_matrix = std::move(matrix_to_move);

  EXPECT_EQ(existed_matrix.GetRows(), 2);
  EXPECT_EQ(existed_matrix.GetColumns(), 1);
  EXPECT_THAT(existed_matrix.GetData(), ElementsAre(1, 2));
  EXPECT_EQ(matrix_to_move.GetData().size(), 0);  // actually moved
}

TEST(MatrixConstructors, ThrowIfRowsOrColumnsNegative) {
  EXPECT_THROW(s21::S21Matrix matrix(-3, 3), std::invalid_argument);
}

TEST(MatrixConstructors, ThrowIfRowsInitializerListNotMatchRowsAndColumns) {
  EXPECT_THROW(s21::S21Matrix matrix(2, 2, {1, 0}), std::invalid_argument);
}

TEST(MatrixConstructors, ThrowIfListOfListNotMatchRows) {
  EXPECT_THROW(s21::S21Matrix matrix(2, 2,
                                     {
                                         // Only two rows expected
                                         {1, 2},
                                         {3, 4},
                                         {5, 6},
                                     }),
               std::invalid_argument);
}

TEST(MatrixConstructors, ThrowIfListOfListNotMatchColumns) {
  EXPECT_THROW(
      s21::S21Matrix matrix(2, 2,
                            {
                                {1, 2, 3},  // Only two columns expected
                                {3, 4},
                                {5, 6},
                            }),
      std::invalid_argument);
}
