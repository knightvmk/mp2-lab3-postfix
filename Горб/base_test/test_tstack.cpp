#include "stack.h"
#include <gtest.h>

TEST(TStack, operation_pop_push_is_true)
{
	TStack<double> a(2);
	a.Push(3);
	a.Push(4);
	double k = a.Pop();
	EXPECT_EQ(3,a.Pop);
}

TEST(TStack, can_check_isfull_stack)
{
	TStack<int> a(2);
	a.Push(50);
	int a = a.Pop();
	EXPECT_EQ(false, a.IsFull());
}

TEST(TStack, can_check_isempty_stack)
{
	TStack<int> a(2);
	a.Push(3);
	int a = a.Pop();
	EXPECT_EQ(true, a.IsEmpty);
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
	EXPECT_EQ(a.Top(), a.Pop());
}
