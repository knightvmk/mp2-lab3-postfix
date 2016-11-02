#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> a(5));
}

TEST(TStack, throw_create_stack_with_overmax_lenght)
{
	ASSERT_ANY_THROW(TStack<int> a(105));
}

TEST(TStack, throw_create_stack_with_negative_lenght)
{
	ASSERT_ANY_THROW(TStack<int> a(-4));
}

TEST(TStack, throw_create_stack_with_zero_lenght)
{
	ASSERT_ANY_THROW(TStack<int> a(0));
}

TEST(TStack, operation_pop_push_is_true)
{
	TStack<double> a(2);
	a.Push(3);
	a.Push(4);
	double k = a.Pop();
	EXPECT_EQ(3,a.Pop());
}

TEST(TStack, can_check_isfull_stack)
{
	TStack<int> a(2);
	a.Push(50);
	int b = a.Pop();
	EXPECT_EQ(false, a.IsFull());
}

TEST(TStack, can_check_isempty_stack)
{
	TStack<int> a(2);
	a.Push(3);
	int b = a.Pop();
	EXPECT_EQ(true, a.IsEmpty());
}

TEST(TStack, throw_cant_pop_from_empty_stack)
{
	TStack<int> a(2);
	ASSERT_ANY_THROW(a.Pop());
}

TEST(TStack, cant_operation_top_to_change_stack)
{
	TStack<char> a(2);
	a.Push('K');
	char r = a.Top();
	EXPECT_EQ(a.Top(), 'K');
}
