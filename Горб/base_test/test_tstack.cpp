#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> a(5));
}

TEST(TStack, throw_create_stack_with_overmax_lenght)
{
	ASSERT_ANY_THROW(TStack<int> a(MSIZE_STACK+1));
}

TEST(TStack, throw_create_stack_with_negative_lenght)
{
	ASSERT_ANY_THROW(TStack<int> a(-4));
}

TEST(TStack, throw_create_stack_with_zero_lenght)
{
	ASSERT_ANY_THROW(TStack<int> a(0));
}

TEST(TStack, throw_push_to_override_stack)
{
	TStack<int> a(2);
	a.Push(2);
	a.Push(3);
	ASSERT_ANY_THROW(a.Push(7));
}

TEST(TStack, throw_pop_from_empty_stack)
{
	TStack<int> a(2);
	ASSERT_ANY_THROW(a.Pop());
}

TEST(TStack, throw_top_from_empty_stack)
{
	TStack<double> a(3);
	ASSERT_ANY_THROW(a.Top());
}

TEST(TStack, can_change_count_after_push)
{
	TStack<int> a(3);
	a.Push(3);
	EXPECT_EQ(1, a.GetCount());
}

TEST(TStack, can_change_count_after_pop)
{
	TStack<double> b(3);
	b.Push(5);
	b.Pop();
	EXPECT_EQ(0, b.GetCount());
}

TEST(TStack, operator_top_cant_change_count)
{
	TStack<char> a(2);
	a.Push('m');
	EXPECT_EQ(1, a.GetCount());
}

TEST(TStack, operation_pop_push_is_true)
{
	TStack<double> a(2);
	a.Push(3);
	a.Push(4);
	double k = a.Pop();
	EXPECT_EQ(3, a.Pop());
}

TEST(TStack, can_check_no_isfull_stack)
{
	TStack<int> a(2);
	a.Push(50);
	int b = a.Pop();
	EXPECT_EQ(false, a.IsFull());
}

TEST(TStack, can_check_real_isfull_stack)
{
	TStack<int> a(2);
	a.Push(9);
	int b = a.Pop();
	a.Push(4);
	a.Push(99);
	EXPECT_EQ(true, a.IsFull());
}

TEST(TStack, can_check_no_isempty_stack)
{
	TStack<int> a(2);
	a.Push(6);
	int b = a.Pop();
	a.Push(4);
	EXPECT_EQ(false, a.IsEmpty());
}

TEST(TStack, can_check_real_isempty_stack)
{
	TStack<int> a(2);
	a.Push(3);
	int b = a.Pop();
	EXPECT_EQ(true, a.IsEmpty());
}

TEST(TStack, cant_operation_top_to_change_stack)
{
	TStack<char> a(2);
	a.Push('K');
	char r = a.Top();
	EXPECT_EQ(a.Top(), 'K');
}


