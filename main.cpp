/*
Унарная операция 
Создать кдасс целых чисел (long). Определть операторы --(префексная форма, метод) для вычитания пользовского значения, 
--(постфиксная форма, метод) для вычитания 1, ++ (префиксная форма, дружественная функция) для прибавления пользовательского значения, 
++ (постфиксная форма, дружественная функция) для прибавления 1. Оператор ! возвращает отрицательное значение.  
Бинарные операция 
Создать объект "стек", размеры стека задаются пользователем с клавиатуры, 
значения также вводятся с клавиатуры. Перегрузить операции половину как методы, 
половину как дружественные функций "+, +=, -, -=, *, *=, /, /=" для работы с числами
*/
#include <iostream>
#include <conio.h>
using namespace std;

#include "myLong.h"
#include "stack.h"
#include "myException.h"

int main(void)
{
	cout << "Answer 1" << endl; 
	myLong a;
	cout << "a++\t" << a++ << endl;
	cout << "++a\t" << ++a << endl;
	cout << "a--\t" << a-- << endl;
	cout << "--a\t" << --a << endl;
	cout << "!a\t" << !a << endl;

	cout << "Answer 2" << endl;
	size_t b;
	cout << "Enter stack size:";
	cin >> b;
	stack st(b);
	cout << "Enter reserve stack size:";
	cin >> b;
	stack st2(b);
	double num;
	char c;
	for(;;)
	{
		try
		{
			switch(c = _getch())
			{
			case '0':
				cout << st.getSize() << endl;
				break;
			case '1':
				cout << "Enter num, for operation: ";
				cin >> num;
				st.push(new elem(num));
				break;
			case '2':
				cout << st.pop();
				break;
			case '3':
				cout << st2.pop();
				break;
			case '4':
				st.fill();
				st2.fill();
				break;
			case '5':
				st.clear();
				st2.clear();				
				break;
			case '6':
				st2 = st;
				cout << st2;
				break;
			case '7':
				cout << -st;
				break;
			case '8':
				cout << "Enter number: ";
				cin >> num;
				cout << st-num;
				break;
			case '9':
				cout << st-st2;
				break;
			case 'a':
				cout << "Enter number: ";
				cin >> num;
				st-=num;
				cout << st;
				break;
			case 'b':
				st-=st2;
				cout << st;
				break;
			case 'c':
				cout << "Enter number: ";
				cin >> num;
				cout << st + num;
				break;
			case 'd':
				cout << st + st2;
				break;
			case 'e':
				cout << "Enter number: ";
				cin >> num;
				st += num;
				cout << st;
				break;
			case 'f':
				st += st2;
				cout << st;
				break;
			case 'g':
				cout << "Enter number: ";
				cin >> num;
				cout << st * num;
				break;
			case 'h':
				cout << "Enter number: ";
				cin >> num;
				st *= num;
				cout << st;
				break;
			case 'i':
				cout << "Enter number: ";
				cin >> num;
				cout << st / num;
				break;
			case 'j':
				cout << "Enter number: ";
				cin >> num;
				st /= num;
				cout << st;
				break;
			case 'k':
				cout << "0 - size base stack" << endl;
				cout << "1 - push in base stack " << endl;
				cout << "2 - pop on base stack" << endl;
				cout << "3 - pop on extra stack" << endl;
				cout << "4 - fill all stack" << endl;
				cout << "5 - clear all stack" << endl;
				cout << "6 - extra stack = base stack" << endl;
				cout << "7 - -base stack" << endl;
				cout << "8 - base stack -  numeric" << endl;
				cout << "9 - base stack -  extra stack" << endl;
				cout << "a - base stack -= numeric" << endl;
				cout << "b - base stack -= extra stack" << endl;
				cout << "c - base stack +  numeric" << endl;
				cout << "d - base stack +  extra stack" << endl;
				cout << "e - base stack += numeric" << endl;
				cout << "f - base stack += extra stack" << endl;
				cout << "g - base stack *  numeric" << endl;
				cout << "h - base stack *= numeric" << endl;
				cout << "i - base stack /  numeric" << endl;
				cout << "j - base stack /= numeric" << endl;
				cout << "k - help" << endl;
				cout << "l - exit" << endl;
				cout << "m - push in extra stack" << endl;
				cout << "n - show extra and base" << endl;
				break;
			case 'l':
				return 0;
				break;
			case 'm':
				cout << "Enter num, for operation: ";
				cin >> num;
				st2.push(new elem(num));
				break;
			case 'n':
				cout << "base stack" << endl;
				cout << st;
				cout << "extra stack" << endl;
				cout << st2;
			default:
				cout << "Command " << c << " undefined" <<endl << "help - k" << endl; 
				break;
			}
		}
		catch(myException e)
		{
			cout << e << endl;
		}
	}
}