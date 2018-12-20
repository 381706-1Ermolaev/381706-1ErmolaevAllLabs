#include "gtest.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

TEST(TMatrix, can_get_size)
{
	TMatrix<int> A(5);
	ASSERT_EQ(5, A.getSize());
}

TEST(TMatrix, throws_when_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<int> A(-5));
}

TEST(TMatrix, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW(TMatrix<int> A(5));
}


TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> A(5);
	ASSERT_NO_THROW(TMatrix<int> B(A));
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> A(4);
	A[0][3] = 3;
	EXPECT_EQ(3, A[0][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> A(4);
	ASSERT_ANY_THROW(A[-5][1] = 3);
}


TEST(TMatrix, can_assign_matrix_of_equal_size)
{
	TMatrix<int> A(4);
	TMatrix<int> B(4);
	ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, can_assign_matrix_of_different_size)
{
	TMatrix<int> A(4);
	TMatrix<int> B(5);
	ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> A(4);
	TMatrix<int> B(4);
	ASSERT_NO_THROW(A == B);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> A(4);
	ASSERT_NO_THROW(A == A);
}

TEST(TMatrix, matrix_with_different_size_are_not_equal)
{
	TMatrix<int> A(4);
	TMatrix<int> B(10);
	ASSERT_ANY_THROW(A == B);
}

TEST(TMatrix, can_add_matrix_with_equal_size)
{
	TMatrix<int> A(4);
	TMatrix<int> B(4);
	ASSERT_NO_THROW(A + B);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> A(4);
	TMatrix<int> B(10);
	ASSERT_ANY_THROW(A + B);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> A(4);
	TMatrix<int> B(4);
	ASSERT_NO_THROW(A - B);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> A(4);
	TMatrix<int> B(10);
	ASSERT_ANY_THROW(A - B);
}

TEST(TMatrix, can_division)
{
	TMatrix<double> A(2);
	TMatrix<double> B(2);
	TMatrix<double> C(2);
	A[0][0] = 1;
	A[1][0] = 1;
	B[0][0] = 0.5;
	B[1][0] = 0.5;
	C[0][0] = 2;
	C[1][0] = 2;
	
	ASSERT_TRUE(C == A / B);
}

TEST(TMatrix, cant_division_dif_size)
{
	TMatrix<double> A(2);
	TMatrix<double> B(3);
	
	ASSERT_ANY_THROW(A / B);
	
}