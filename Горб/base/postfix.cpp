#include "postfix.h"
#include "stack.h"
#define MAX_TEMP 30 //const for realloc temp mem to put spaces
#define MAX_SIZE 30 // const for operate with postfix in ToPostfix

TPostfix::TPostfix()
{
	infix ="";
	postfix ="";
}

TPostfix::TPostfix(const string &enter)
{
	infix = enter;
	postfix.resize(enter.length());
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
	case '^':
		return 4;
	case '(':
		return 1;

	} return -1;
}

void TPostfix::SetInfix(const string &enter)
{
	infix = enter;
	postfix.resize(enter.length());
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

bool TPostfix::IsDigit(int i)
{
	if (postfix[i] >= '0' && postfix[i] <= '9')
		return true;
	else return false;
}
bool TPostfix::IsChar(int i)
{
	if (!IsDigit(i)) return true;
	else return false;
}

string TPostfix::ToPostfix()
{
	TStack<char> op(12);
	int j = 0; 
	postfix.resize(infix.length()+MAX_TEMP); 
	for (register int i = 0; i < infix.length(); i++)
	{

		if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '^' && infix[i] != '(' && infix[i]!=')')
		{
			postfix[j++] = infix[i]; 
			if (infix[i + 1] == '+' || infix[i + 1] == '-' || infix[i + 1] == '*' || infix[i + 1] == '^' || infix[i + 1] == '/' || infix[i + 1] == '(' || infix[i + 1] == ')')
				postfix[j++] = ' ';
		}
		if (infix[i] == '(') op.Push(infix[i]);
		if (infix[i] == ')')
		{
			while (op.Top() != '(')
				postfix[j++] = op.Pop();
			while (op.Top() =='(') op.Pop();
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '^' || infix[i] == '/' || infix[i] == '(')
		{
			if (op.IsEmpty() || op.Top()== '(') 
				op.Push(infix[i]);
			else if (prior(op.Top()) < prior(infix[i])) 
				op.Push(infix[i]);
			else
			{
				while (!op.IsEmpty() && prior(op.Top()) >= prior(infix[i])) 
				{
					postfix[j++] = op.Pop();
				}
				op.Push(infix[i]);
			}
		}
		 /*if (infix[i] == ')')
		{
			while (op.Top() != '(')
				postfix[j++] = op.Pop();
			op.Pop();
		}*/
	}
	while (!op.IsEmpty())
		postfix[j++] = op.Pop();
	postfix.erase(j, postfix.length());
	/*for (register int i = 0; i<postfix.length(); i++)
	{
		if (postfix[i] == ' ')
			postfix.erase(i--, 1);
	}*/
	return postfix;
}

double TPostfix::Calculate()
{
	TStack<double> calc(postfix.length()); 
	double digit1, digit2,on;
	int j;
	for (register int i = 0; i < postfix.length(); i++)
	{
		if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '^' && postfix[i] != ' ')
		{
			if (!IsDigit(i))
			{
				j = i;
				while (postfix[j] >= 'A' && postfix[j] <= 'z')
				{
					printf("%c", postfix[j++]);
				}
				i = j - 1;
				scanf_s("%lf", &on);
			}
			else
			{
				j = i;
				int k = 0;
				while (postfix[j] >= '0' && postfix[j] <= '9')
				{
					k++;
					j++;
				}
				j = i;
				char *res=new char[k];
				k = 0;
				while (postfix[j] >= '0' && postfix[j] <= '9')
				{
					res[k++] = postfix[j++];
				}
				res[k] = '\0';
				on = atof(res);
				i = j;
			}
			calc.Push(on);
		}
		switch (postfix[i])
		{
		case '+':
		{
			digit1 = calc.Pop();
			digit2 = calc.Pop();
			calc.Push(digit1 + digit2);
			break;
		}
		case '-':
		{
			digit1 = calc.Pop();
			digit2 = calc.Pop();
			calc.Push(digit2 - digit1);
			break;
		}
		case '*':
		{
			digit1 = calc.Pop();
			digit2 = calc.Pop();
			calc.Push(digit1 * digit2);
			break;
		}
		case '/':
		{
			digit1 = calc.Pop();
			digit2 = calc.Pop();
			calc.Push(digit2 / digit1);
			break;
		}
		case '^':
		{
			digit1 = calc.Pop();
			digit2 = calc.Pop();
			calc.Push(pow(digit2, digit1));
			break;
		}
		}
	}
	return calc.Pop();
}

void TPostfix::WatchLen()
{
	printf("\ninf = %i post = %i\n", infix.length(), postfix.length());
}

void TPostfix::WatchSize()
{
	printf("\ninf = %i post = %i\n", infix.size(), postfix.size());
}
