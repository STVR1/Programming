#include <iostream>
#include <cmath>
#include<iomanip>
#include<string>
#include<regex>
#include<algorithm>
#include<conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double z1, z2;
	int key = 13;
	const double PI = 3.145926;
	string a;
	regex b("([\\digit]+)");
	regex d("(\-)""([\\digit]+)");
	regex e("(\-)""([\\digit]+)""(\.)""([\\digit]+)");
	regex f("([\\digit]+)""(\.)""([\\digit]+)");
	cout << "Введите значение в радианах\n";
	getline(cin, a);
	cout << "Нажмите два раза enter\n";
	key = _getch();
	switch (key) {
	case 13: break;
	default: while(key!=13){
		cout << "Нажмите два раза enter\n";
		key = _getch();
	}
	}
	while (!regex_match(a, b) 
		&& !regex_match(a,d)
		&& !regex_match(a, e)
		&& !regex_match(a,f)

		 ) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода! Введи повторно в радианах!!!\n";
		getline(cin, a);
		cout << "Нажмите два раза enter\n";
		key = _getch();
		switch (key) {
		case 13: break;
		default: while (key != 13) {
			cout << "Нажмите два раза enter\n";
			key = _getch();
		}
		}
	}
	double c = stoi(a);
	z1 = 2 * pow(sin(3 * PI - 2 * c), 2) * pow(cos(5 * PI + 2 * c), 2);
	z2 = 1. / 4 - 1. / 4 * sin(5. / 2 * PI - 8 * c);
	cout << "Результат z1: " << setprecision(1) << z1 << endl;
	cout << "Результат z2: " << setprecision(1) << z2 << endl;
	cout << "z1=z2";
	system("pause");
	return 0;
}