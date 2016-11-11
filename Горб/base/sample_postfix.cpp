#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  
  double res;

  setlocale(LC_ALL, "Russian");
  cout << "Введите арифметическое выражение: ";
  getline(cin, expression); //true enter 
  //cin >> expression;
  cout << "Ваш ввод: "<< expression << endl; 
  TPostfix postfix(expression); //set postfix
  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl; //return with space expression
  postfix.ToPostfix(); 
  postfix.WatchLen(); //for debug
  postfix.WatchSize(); /for debug
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl; //inject nospace expression.infix to postfix
  res = postfix.Calculate();
  cout << "Результат: " << res << endl;
  system("pause");
  return 0;
}
