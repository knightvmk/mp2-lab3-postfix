#ifndef __STACK_H__
#define __STACK_H__

const int MSIZE_STACK=100;

template <class type>
class TStack
{
private:
  type *pMem;
  int size;
  int count;
public:
	TStack(int len);
	~TStack();
	int GetSize();
	bool IsFull();
	bool IsEmpty();
	type Pop();
	type Top();
	void Push(type val);
};

template <class type>
TStack<type>::TStack(int len)
{
	if ((len < 1) || (len > MSIZE_STACK))
		throw len;
	size = len;
	count = 0;
	pMem = new type[size];
}

template <class type>
TStack<type>::~TStack()
{
	delete[] pMem;
	pMem = 0;
}

template <class type>
int TStack<type>::GetSize()
{ return size; }

template <class type>
bool TStack<type>::IsFull()
{
	return (count==size);
}

template <class type>
bool TStack<type>::IsEmpty()
{
	return (count == 0);
}

template <class type>
type TStack<type>::Pop()
{
	if (IsEmpty()) throw ("Fail Pop. Stack is Empty");
	if (!IsEmpty()) return pMem[(count--) - 1];
}

template <class type>
type TStack<type>::Top()
{
	if (IsEmpty())	throw ("Fail Top. Stack is empty");
	if (!IsEmpty())	return pMem[(count - 1)];
}

template <class type>
void TStack<type>::Push(type val)
{
	if (IsFull()) throw ("Fail push. Override stack");
	if (!IsFull())	pMem[count++] = val;
}
#endif
