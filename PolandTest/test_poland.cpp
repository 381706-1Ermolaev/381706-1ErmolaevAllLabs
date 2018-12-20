#include "gtest.h"
#include "Poland.h"

TEST(Poland, can_add) {
	TString A(3, "9+8");
	TQueue<char> B(One(A));

	EXPECT_EQ(17, f(B));
}

TEST(Poland, can_add_two_digit_number) {
	TString A(5, "43+57");
	TQueue<char> B(One(A));

	EXPECT_EQ(100, f(B));
}

TEST(Poland, negative_number) {
	TString A(5, "-1000");
	TQueue<char> B(One(A));

	EXPECT_EQ(-1000, f(B));
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

TEST(Poland, can_multi_1) {
	TString A(10, "(43+57)*43");
	TQueue<char> B(One(A));

	EXPECT_EQ(4300, f(B));
}

TEST(Poland, can_multi_2) {
	TString A(10, "(43+57)/20");
	TQueue<char> B(One(A));

	EXPECT_EQ(5, f(B));
}

TEST(Poland, can_multi_3) {
	TString A(14, "(43+57)/(20+5)");
	TQueue<char> B(One(A));

	EXPECT_EQ(4, f(B));
}

TEST(Poland, can_multi_with_negative_first_number) {
	TString A(13, "-5+(43+57)/20");
	TQueue<char> B(One(A));

	EXPECT_EQ(0, f(B));
}













