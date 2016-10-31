#include "postfix.h"
#include "stack.h"



string TPostfix::ToPostfix()
{
	TStack<char> operation(10);
	for (register int i = 0; i < postfix.length; i++)
	{
		if (operation.IsEmpty() || operation.Top() == '(') 
			operation.Push(postfix[i]);
		//
	}
  return postfix;
}

double TPostfix::Calculate()
{
  return 0;
}
