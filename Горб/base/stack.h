#ifndef __STACK_H__
#define __STACK_H__

const int MSIZE_STACK;

template <class type>
class TStack
{
private:
  Type *pMem;
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
	int Prior();
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
	return (count==MSIZE_STACK)
}

template <class type>
bool TStack<type>::IsEmpty()
{
	return (count == 0);
}

template <class type>
type TStack<type>::Pop()
{
	if (count == 0) throw ("Fail pop");
	return pMem[(count--) - 1];
}

template <class type>
type TStack<type>::Top()
{
	return pMem[(count--)];
}

template <class type>
void TStack<type>::Push(type val)
{
	if (IsFull())
	{
		throw ("Fail push");
		return;
	}
	pMem[count++] = val;
}

template <class type>
int TStack<type>::Prior()
{
	if (Top() == "+" || Top() == "-") return 1;
	if (Top() == "*" || Top() == "/") return 2;
	if (Top() == "(") return 3;
	if (Top() == "0") return 0;
	else return -1;
}
#endif
