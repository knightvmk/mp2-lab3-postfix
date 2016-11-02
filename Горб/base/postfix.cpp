#include "postfix.h"
#include "stack.h"

int TPostfix::prior(char c) //for search priority
{
	switch (c)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '(':
		return 1;

	} return -1;
}

string TPostfix::ToPostfix()
{
	char not;
	string origin_infix = infix;
	TStack<char> op(12);
		//clear tab, space symbols;
	for(register int i=0;i<infix.size();i++)
	{
		if (infix[i] == ' ')
			infix.erase(i--, 1);
	}
		//we have a clear infix string without spaces
	for (register int i = 0, j=0; i < infix.size(); i++)
	{
		if (infix[i] != '+' || infix[i] != '-' || infix[i] != '*' || infix[i] != '/' || infix[i] != '(')
		{
			postfix[j] = infix[i];
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '(')
		{
			if (op.IsEmpty() || prior(op.Top())<prior(infix[i]) || infix[i]=='(')
			op.Push(infix[i]);
			while (!op.IsEmpty() && ((op.Top()) >= prior(infix[j])))
			{
				postfix[j] = op.Pop();
				j++;
			}
			j = i;
		}
		else if (infix[i] == ')')
		{
			while (op.Top() != '(')
			{
				postfix[j] = op.Pop();
				j++;
			}
			j = i;
			if (op.Top() == '(') not= op.Pop();
		}
		j = i;
		if (i = infix.size() && !op.IsEmpty())
			while (!op.IsEmpty())
				postfix[j] = op.Pop();
	}
	infix = origin_infix;
	return postfix;
}

double TPostfix::Calculate()
{
  return 0;
}
