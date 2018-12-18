#include "gtest.h"
#include "Vector.h"
#include "ME.h"

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> A(5)); //проверка на отсутствие исключений в конструкторе
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> A(-5)); //проверка на исключения 
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> A(5);
	ASSERT_NO_THROW(TVector<int> B(A));
}

TEST(TVector, new_vector_is_set_to_zero)
{
	TVector<int> A(20);
	int sum = 0;
	for (int i = 0; i < 20; i++)
		sum += A[i];
	EXPECT_EQ(0, sum);
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> A(4);
	A[2] = 4;
	EXPECT_EQ(4, A[2]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> A(5);
	ASSERT_ANY_THROW(A[-4] = 9);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> A(5);
	ASSERT_ANY_THROW(A[20] = 9);
}

TEST(TVector, can_get_size)
{
	TVector<int> A(66);
	EXPECT_EQ(66, A.getSize());
}



TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> A(5);
	ASSERT_ANY_THROW(A = A);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> A(5);
	TVector<int> B(5);
	ASSERT_NO_THROW(A = B);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> A(5);
	TVector<int> B(8);
	ASSERT_NO_THROW(A = B);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> A(5);
	TVector<int> B(5);
	ASSERT_EQ(true,A==B);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> A(5);
	ASSERT_EQ(true, A == A);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> A(5);
	TVector<int> B(8);
	ASSERT_EQ(false, A == B);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> A(5);
	TVector<int> B(5);
	ASSERT_NO_THROW(A + B);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> A(5);
	TVector<int> B(8);
	ASSERT_ANY_THROW(A + B);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> A(5);
	TVector<int> B(5);
	ASSERT_NO_THROW(A - B);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> A(5);
	TVector<int> B(8);
	ASSERT_ANY_THROW(A - B);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> A(5);
	TVector<int> B(5);
	ASSERT_NO_THROW(A * B);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> A(5);
	TVector<int> B(8);
	ASSERT_ANY_THROW(A * B);
}












