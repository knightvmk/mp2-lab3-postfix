#include "postfix.h"
#include "stack.h"
#define MAX_SIZE 30 // const for operate with postfix in ToPostfix

TPostfix::TPostfix()
{
	infix = "";
	postfix = "";
}

TPostfix::TPostfix(const string &enter)
{
	infix = enter;
	postfix.resize(enter.size());
	EraseSpace();
}

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

void TPostfix::SetInfix(const string &enter)
{
	infix = enter;
	postfix.resize(enter.size());
	EraseSpace();
}

void TPostfix::EraseSpace() //for true and exellent view
{
	for (register int i = 0; i<infix.length(); i++)
	{
		if (infix[i] == ' ')
			infix.erase(i--, 1);
	}
}

string TPostfix::ToPostfix()
{
	char not;
	string origin_infix = infix;
	TStack<char> op(12);
		//clear tab, space symbols;
		//do extern function for delete spaces // look up
		//we have a clear infix string without spaces
	int j = 0; //for access and work with postfix
	postfix.resize(MAX_SIZE); //for normal work
	for (register int i = 0; i < infix.length(); i++,j++)
	{
		if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '(' && infix[i]!=')')
		{
			postfix[j++] = infix[i]; //any letter to postfix

		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '(')
		{
			if (op.IsEmpty() || op.Top()== '(') //oldbug: (op.IsEmpty() || prior(op.Top()) < prior(infix[i]) || infix[i] == '(')
				op.Push(infix[i]);
			else if (prior(op.Top()) < prior(infix[i])) //divide operation "if" is requires
				op.Push(infix[i]);
			else
			{
				while (!op.IsEmpty() && prior(op.Top()) >= prior(infix[i])) //execute
				{
					postfix[j++] = op.Pop();
				}
				op.Push(infix[i]);
			}
		}
		 if (infix[i] == ')')
		{
			while (op.Top() != '(')
			{
				postfix[j++] = op.Pop();
			}
			not= op.Pop(); //delete "trash"
			//if (op.Top() == '(') not= op.Pop();
		}
		// if (infix[i] == '(') // look up to "oldbug"
		//	 op.Push(infix[i]);
		// if (i = infix.size() && !op.IsEmpty())
	}
	while (!op.IsEmpty())
		postfix[j] = op.Pop();
	infix = origin_infix;
	/*for (register int i = 0; i<postfix.length(); i++) ??not actually
	{
		if (postfix[i] == ' ')
			postfix.erase(i--, 1);
	}*/
	return postfix;
}

double TPostfix::Calculate()
{
  return 0;
}
