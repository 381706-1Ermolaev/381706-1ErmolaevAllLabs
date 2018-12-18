#include "gtest.h"
#include "Poland.h"

TEST(Poland, can_add) {
	TString A(3, "9+8");
	TQueue<char> B(One(A));

	EXPECT_EQ(17, f(B));
}

TEST(Poland, can_add_3_param) {
	TString A(5, "9+8+2");
	TQueue<char> B(One(A));

	EXPECT_EQ(19, f(B));
}

TEST(Poland, can_subtract) {
	TString A(3, "9-8");
	TQueue<char> B(One(A));

	EXPECT_EQ(1, f(B));
}


TEST(Poland, can_multiplication) {
	TString A(3, "9*8");
	TQueue<char> B(One(A));

	EXPECT_EQ(72, f(B));
}

TEST(Poland, can_multiplication_3_param) {
	TString A(5, "9*8*2");
	TQueue<char> B(One(A));

	EXPECT_EQ(144, f(B));
}

TEST(Poland, can_multiplication_and_add_whith_hooks) {
	TString A(7, "(9+8)*2");
	TQueue<char> B(One(A));

	EXPECT_EQ(34, f(B));
}

TEST(Poland, can_multiplication_and_add_whithout_hooks) {
	TString A(5, "9+8*2");
	TQueue<char> B(One(A));

	EXPECT_EQ(25, f(B));
}

TEST(Poland, can_split) {
	TString A(3, "8/2");
	TQueue<char> B(One(A));

	EXPECT_EQ(4, f(B));
}















