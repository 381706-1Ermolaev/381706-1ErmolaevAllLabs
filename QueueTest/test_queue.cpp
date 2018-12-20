#include "gtest.h"
#include "Queue.h"


TEST(TQueue, can_create_queue_with_positive_size){
	ASSERT_NO_THROW(TQueue<int> test1(5));
}

TEST(TQueue, cant_create_queue_with_negative_size){
	ASSERT_ANY_THROW(TQueue<int> test1(-5));
}

TEST(TQueue, can_create_copied_queue){
	TQueue<int> test1(5);
	ASSERT_NO_THROW(TQueue<int> B(test1));
}

TEST(TQueue, check_full_queue){
	TQueue<int> test1(1);
	test1.Put(1);
	EXPECT_EQ(1, test1.IsFull());
}

TEST(TQueue, check_empty_queue){
	TQueue<int> test1(6);
	EXPECT_EQ(1, test1.IsEmpty());
}

TEST(TQueue, cant_put_element_in_full_queue){
	TQueue<int> test1(4);
	for(int i=0;i<4;i++)
		test1.Put(43);

	ASSERT_ANY_THROW(test1.Put(43));
}

TEST(TQueue, cant_get_element_in_empty_queue){
	TQueue<int> test1(4);

	ASSERT_ANY_THROW(test1.Get());
}

TEST(TQueue, can_put_element){
	TQueue<int> test1(4);

	ASSERT_NO_THROW(test1.Put(43));
}

TEST(TQueue, can_get_element){
	TQueue<int> test1(4);
	test1.Put(43);

	EXPECT_EQ(43, test1.Get());
}

