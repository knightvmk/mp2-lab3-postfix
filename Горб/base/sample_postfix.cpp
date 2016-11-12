#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

void ShowRule()
{
	printf("\nПравило пользования программой:\n");
	printf("  1) В качестве переменных необходимо вводить слова без содержания цифр,\n");
	printf("  2) В качестве констант необходимо вводить только цифры, представляющие число,\n");
	printf("  3) После перевода в постфиксную форму небходимо ввести значения переменных.\n");
}

int main()
{
  string expression;
  
  double res;

  setlocale(LC_ALL, "Russian");
  ShowRule();
  cout << "Введите арифметическое выражение: ";
  getline(cin, expression); //true enter 
  //cin >> expression;
  cout << "Ваш ввод: "<< expression << endl; 
  TPostfix postfix(expression); //set postfix
  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl; //return with space expression
  postfix.ToPostfix();
  postfix.WatchLen(); //for debug
  postfix.WatchSize(); //for debug
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl; //inject nospace expression.infix to postfix
  res = postfix.Calculate();
  cout << "Результат: " << res << endl;
  system("pause");
  return 0;
}

