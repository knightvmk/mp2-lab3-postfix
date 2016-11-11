#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <iostream>
#include "stack.h"


using namespace std;

const struct prior
{
	char op;
	int pr;
};

class TPostfix
{
private:
  string infix;
  string postfix;
  void EraseSpace();
  int prior(char c);
public:

  TPostfix();
  TPostfix(const string &enter);
  void SetInfix(const string &enter);
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  void WatchLen()
  {
	  printf("\ninf = %i post = %i\n", infix.length(), postfix.length());
  }
  void WatchSize()
  {
	  printf("\ninf = %i post = %i\n", infix.size(), postfix.size());
  }
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
