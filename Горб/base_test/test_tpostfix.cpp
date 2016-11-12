#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix a());
}

TEST(TPostfix, can_create_postfix_by_string)
{
	string b = "a+b-c";
	ASSERT_NO_THROW(TPostfix a(b));
}

TEST(TPostfix, throw_first_operand_is_not_value)
{
	string b = "-a+b";
	TPostfix a(b);
	ASSERT_ANY_THROW(a.ToPostfix());
}

TEST(TPostfix, can_erase_spaces_string_infix_by_constructor)
{
	string bad = "  a     +   b    ";
	TPostfix a(bad);
	EXPECT_EQ("a+b", a.GetInfix());
}

TEST(TPostfix, can_erase_spaces_string_infix_by_method)
{
	string bad = "     z   *  q   ";
	string els = "";
	TPostfix am(els);
	am.SetInfix(bad);
	EXPECT_EQ("z*q", am.GetInfix());
}

TEST(TPostfix, can_topostfix_two_value)
{
	string b = "a+b";
	TPostfix a(b);
	EXPECT_EQ("a b+", a.ToPostfix());
}

TEST(TPostfix, can_topostfix_three_value_by_linear)
{
	string b = "a+b+c";
	TPostfix a(b);
	EXPECT_EQ("a b +c+", a.ToPostfix());
}

TEST(TPostfix, can_topostfix_four_value_by_linear)
{
	string b = "a+b+c+e";
	TPostfix a(b);
	EXPECT_EQ("a b +c +e+", a.ToPostfix());
}

TEST(TPostfix, can_topostfix_three_value_with_brackets)
{
	string b = "a+(b+c)";
	TPostfix a(b);
	EXPECT_EQ("a b c ++", a.ToPostfix());
}

TEST(TPostfix, can_topostfix_value_and_const)
{
	string b = "a+2";
	TPostfix a(b);
	EXPECT_EQ("a 2+", a.ToPostfix());
}

TEST(TPostfix, can_calculate_two_const)
{
	string b = "6*2";
	TPostfix a(b);
	a.ToPostfix();
	a.Calculate();
	EXPECT_EQ(12., a.Calculate());
}

TEST(TPostfix, can_true_involution_in_zero)
{
	string b = "5^0";
	TPostfix a(b);
	a.ToPostfix();
	EXPECT_EQ(1, a.Calculate());
}

TEST(TPostfix, throw_divide_by_zero)
{
	string b = "10/0";
	TPostfix a(b);
	a.ToPostfix();
	ASSERT_ANY_THROW(a.Calculate());
}

TEST(TPostfix, can_calculate_with_brackets_and_work_priority)
{
	string b = "12/(6/2+9)";
	TPostfix a(b);
	a.ToPostfix();
	a.Calculate();
	EXPECT_EQ(1., a.Calculate());
}

TEST(TPostfix, can_calculate_hard_infix)
{
	string b = "   4^  2 + (  100 / 5 - 20^1) - 0   ";
	TPostfix a(b);
	a.ToPostfix();
	EXPECT_EQ(16, a.Calculate());
}

