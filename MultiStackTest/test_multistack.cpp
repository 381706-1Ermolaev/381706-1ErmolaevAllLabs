#include "gtest.h"
#include "MultiStack.h"

TEST(TMStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TMStack<int> A(5,25));
}

TEST(TMStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TMStack<int> A(5, -1));
}

TEST(TMStack, can_set)
{
	TMStack<int> test1(5, 25);
	ASSERT_NO_THROW(test1.Set(1, 2));
}

TEST(TMStack, can_get)
{
	TMStack<int> test1(5, 25);
	test1.Set(1, 43);
	EXPECT_EQ(43,test1.Get(1));
}

TEST(TMStack, can_check_is_empty)
{
	TMStack<int> test1(5, 25);
	EXPECT_EQ(1, test1.isEmpty(1));
}

TEST(TMStack, can_check_is_full)
{
	TMStack<int> test1(5, 25);
	test1.Set(1, 43);
	test1.Set(1, 43);
	test1.Set(1, 43);
	test1.Set(1, 43);
	test1.Set(1, 43);
	EXPECT_EQ(1, test1.isFull(1));
}
