#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(MatrixCalcComplements, ComplementFor3x3MatrixCalculated) {
  const s21::S21Matrix matrix(3, 3,
                              {
                                  {1., 2., 3.},
                                  {3., 2., 1.},
                                  {7., 5., 2.},
                              });

  s21::S21Matrix complements = matrix.CalcComplements();

  EXPECT_EQ(complements.Rows(), 3);
  EXPECT_EQ(complements.Columns(), 3);
  EXPECT_TRUE(complements == s21::S21Matrix(3, 3,
                                            {
                                                {-1., 1., 1.},
                                                {11., -19., 9.},
                                                {-4., 8., -4.},
                                            }));
}

TEST(MatrixCalcComplements, ComplementsForNotSimpleMatrixCalculatedOk) {
  const s21::S21Matrix matrix(4, 4,
                              {
                                  {1.80377, 3.93870, 3.13429, 2.28155},
                                  {1.39307, 1.05586, 2.21357, 2.20440},
                                  {2.74323, 2.41325, 3.86805, 2.73013},
                                  {2.29065, 3.09765, 1.84139, 3.86339},
                              });

  s21::S21Matrix complements = matrix.CalcComplements();

  EXPECT_TRUE(
      complements ==
      s21::S21Matrix(
          4, 4,
          {
              {-8.0642664633, 4.1987149757, 3.1661056480, -0.0941589509},
              {-19.1443430067, -4.4198224214, 8.7731760020, 10.7131854857},
              {15.1040957594, -1.3457695400, -1.9412358558, -6.9511236616},
              {5.0123523428, 0.9933255993, -5.5038169258, 1.8833757880},
          }));
}

TEST(MatrixCalcComplements, ThrowIfMatrixIsEmpty) {
  s21::S21Matrix empty_matrix;

  EXPECT_THROW(empty_matrix.CalcComplements(), std::logic_error);
}

TEST(MatrixCalcComplements, ThrowIfMatrixNotSquare) {
  s21::S21Matrix matrix(1, 2);

  EXPECT_THROW(matrix.CalcComplements(), std::logic_error);
}
