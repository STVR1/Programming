#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<algorithm>
#include<conio.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	string x1, y1, z1;
	regex b("([\\digits\.-]+)");
	double t,a,c;
	int key;
	again:
	cout << "Введите значение x1 в радианах:\n";
	getline(cin, x1);
	cout << "Введите значение y1 в радианах:\n";
	getline(cin, y1);
	cout << "Введите численное значение z1:\n";
	getline(cin, z1);
	cout << "Нажмите два раза enter\n";
	key = _getch();
	switch (key) {
	case 13: break;
	default: while (key != 13) {
		cout << "Нажмите два раза enter\n";
		key = _getch();
	}
	}
	while (!regex_match(x1, b) 
		|| !regex_match(y1, b) 
		|| !regex_match(z1, b)
		|| count(x1.begin(), x1.end(), '.') > 1
		|| count(y1.begin(), y1.end(), '.') > 1
		|| count(z1.begin(), z1.end(), '.') > 1
		) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода. Введите значения повторно.\n";
		goto again;
	}
	double x2 = stoi(x1); double y2 = stoi(y1); double z2 = stoi(z1);
	a = 0.5 + pow(sin(y2), 2);
	c = 3 - pow(z2, 2) / 5;
	t = ((2 * cos(x2 - M_PI / 6))/a)*(1+(pow(z2,2)/c));
	if (a != 0 && c != 0) {
		cout <<"Значение вычисленного t: "<< t << endl;
	}
	else {
		while (a == 0 || c == 0) {
			cin.clear();
			cin.ignore();
			cout << "Ошибка. Данные значения недействительны.\n";
			goto again;
		}
	}  
	return 0;
}