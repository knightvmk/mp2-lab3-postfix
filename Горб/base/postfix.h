#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
private:
  string infix;
  string postfix;
public:
  TPostfix();
  TPostfix(const string &enter);
  int prior(char c);
  void SetInfix(const string &enter);
  void EraseSpace();
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
