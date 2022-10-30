#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<conio.h>
#include<sstream> 
using namespace std;
int enter(int);
int factorial(int);
float yfunc(float);
float sfunc(int, float, int, float, int, float, float, int);
int main() {
	setlocale(LC_ALL, "Rus");
	string a, b, h, n;
	float x, s = 0, sum = 0, difference = 0;
	int k = 0, k1, n1 = 0, key = 13;
	regex b1("^[-]?[0-9]+[.]?[0-9]*");
	regex b2("^[-]?[0-9]+[.]{1}");
	regex b3("^[1-9]{1}""[0-9]*");
	cout << "Введите a:\n";
	getline(cin, a);
	enter(key);
	while (!regex_match(a, b1) || regex_match(a, b2)
		) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода! Введите повторно a\n";
		getline(cin, a);
		enter(key);
	}
	cout << "Введите b:\n";
	getline(cin, b);
	enter(key);
	while (!regex_match(b, b1) || regex_match(b, b2)
		) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода! Введите повторно b\n";
		getline(cin, b);
		enter(key);
	}
	cout << "Введите h:\n";
	getline(cin, h);
	enter(key);
	while (!regex_match(h, b1) || regex_match(h, b2)
		) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода! Введите повторно h\n";
		getline(cin, h);
		enter(key);
	}
	cout << "Введите n:\n";
	getline(cin, n);
	enter(key);
	while (!regex_match(n, b3)) {
		cin.clear();
		cin.ignore();
		cout << "Ошибка ввода! Введите повторно n\n";
		getline(cin, n);
		enter(key);
	}
	stringstream s1;
	s1 << a;
	float a1;
	s1 >> a1;
	stringstream s2;
	s2 << b;
	float b5;
	s2 >> b5;
	stringstream s3;
	s3 << h;
	float h1;
	s3 >> h1;
	stringstream s4;
	s4 << n;
	float n2;
	s4 >> n2;
	cout << "__________________________________________________________" << endl;
	cout << "Номер"<<"\t" << "x" << "\t" << "Y(x)" << "\t" << "S(x)" << "\t" << "|Y(x)-S(x)|" << "\t" << "Операций" << endl;
	for (k1 = 1, x = a1; x <= b5; k1++, x += h1) {
		sfunc(k, x, n1, sum, n2, s, difference, k1);
	}
	cout << "__________________________________________________________" << endl;
	return 0;
}
int factorial(int n1) {
	if (n1 == 0) return 1;
	if (n1 == 1) return 1;
	return n1 * factorial(n1 - 1);
}
int enter(int key) {
	cout << "Нажмите enter\n";
	key = _getch();
	switch (key) {
	case 13: break;
	default: while (key != 13) {
		cout << "Нажмите enter\n";
		key = _getch();
	}
	}
	return key;
}
float sfunc(int k, float x, int n1, float sum, int n2, float s, float difference, int k1) {
	for (k = 0, sum = 0; k <= n2 - 1; k++) {
		yfunc(x);
		n1 = 2 * k + 1;
		s = pow(-1, k) * pow(x, 2 * k + 1) / factorial(n1);
		sum += s;
		difference = fabs(yfunc(x) - sum);
		if (difference < 0.0001) {
			break;
		}
	}
	cout << k1 << "." << "\t" << x <<"\t" << yfunc(x) << "\t" << sum << "\t" << difference << "\t" << k + 1 << endl;
	return sum;
}
float yfunc(float x) {
	return sin(x);
}