#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<conio.h>
using namespace std;
double fmax(double, double, double);
double fmin(double, double);
int enter(int);
int main() {
	setlocale(LC_ALL, "Rus");
	string x, y, z;
	int key = 13;
	regex b1("([\\digit]+)");
	regex b2("(\-)""([\\digit]+)");
	regex b3("(\-)""([\\digit]+)""(\.)""([\\digit]+)");
	regex b4("([\\digit]+)""(\.)""([\\digit]+)");
	again:
	cout << "Введите значение x:\n";
	getline(cin, x);
	enter(key);
	while (!regex_match(x, b1)
		&& !regex_match(x, b2)
		&& !regex_match(x, b3)
		&& !regex_match(x, b4)) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода. Введите значение повторно.\n";
		cout << "Введите значение x:\n";
		getline(cin, x);
		enter(key);
	}
	cout << "Введите значение y:\n";
	getline(cin, y);
	enter(key);
	while (!regex_match(y, b1)
		&& !regex_match(y, b2)
		&& !regex_match(y, b3)
		&& !regex_match(y, b4)) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода. Введите значение повторно.\n";
		cout << "Введите значение y:\n";
		getline(cin, y);
		enter(key);
	}
	cout << "Введите значение z:\n";
	getline(cin, z);
	enter(key);
	while (!regex_match(z, b1)
		&& !regex_match(z, b2)
		&& !regex_match(z, b3)
		&& !regex_match(z, b4)) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода. Введите значение повторно.\n";
		cout << "Введите значение z:\n";
		getline(cin, z);
		enter(key);
	}
	double x1 = stoi(x);
	double y1 = stoi(y);
	double z1 = stoi(z);
	double m;
	m = fmax(x1, y1, z1) / fmin(x1, y1)+5;
	if (fmin(x1, y1) == 0) {
		cout << "Ошибка. Данные значения недействительны. Введите повторно x и z\n";
		do {
			cout << "Введите значение x:\n";
			getline(cin, x);
			enter(key);
		} while (!regex_match(x, b1)
			&& !regex_match(x, b2)
			&& !regex_match(x, b3)
			&& !regex_match(x, b4));
		do {
			cout << "Введите значение y:\n";
			getline(cin, y);
			enter(key);
		} while (!regex_match(y, b1)
			&& !regex_match(y, b2)
			&& !regex_match(y, b3)
			&& !regex_match(y, b4));
	}
	else {
		cout << m << endl;
	}
	return 0;
}
double fmax(double x1, double z1, double y1){
	if (x1<z1 && y1<z1) {
		return z1;
	}
	else if (x1 < y1 && z1< y1) {
		return y1;
	}
	else if (y1 < x1 && z1 < x1) {
		return x1;
	}
	else {
		return  0;
	}
}
double fmin(double x1, double y1){
	if (x1 < y1) {
		return  x1;
	}
	else if (y1 < x1) {
		return y1;
	}
	else {
		return 0;
	}
}
int enter(int key) {
	cout << "Нажмите два раза enter\n";
	key = _getch();
	switch (key) {
	case 13: break;
	default: while (key != 13) {
		cout << "Нажмите два раза enter\n";
		key = _getch();
	}
	}
	return key;
}