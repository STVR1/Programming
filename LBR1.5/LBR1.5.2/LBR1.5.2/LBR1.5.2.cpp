#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<conio.h>
#include<algorithm>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	double z1;
	double z2;
	double y;
	int key;
	string a;
	regex b("([\\digits\.-]+)");
	cout << "Введите значение угла альфа в градусах\n";
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
		again:
	while (!regex_match(a, b) || count(a.begin(), a.end(), '.') > 1) {
			cin.clear();
			cin.ignore();
			cout << "Ошибка ввода. Введите значение угла в градусах\n";
			getline(cin, a);
			cout << "Нажмите enter два раза\n";
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
		y = cos(c)+1-2*pow(sin(2*c),2);
		z1 = (sin(2 * c) + sin(5 * c) - sin(3 * c)) / y;
		z2 = 2 * sin(c);
		if (y!=0) {
			cout << "z1: " << z1 << endl;
			cout << "z1: " << z2 << endl;
		}
		else {
			while (y == 0) {
				cin.clear();
				cin.ignore();
				cout << "Ошибка ввода или неверное значение. Введите повторно альфа\n";
				getline(cin, a);
				cout << "Нажмите enter два раза\n";
				key = _getch();
				switch (key) {
				case 13: break;
				default: while (key != 13) {
					cout << "Нажмите два раза enter\n";
					key = _getch();
				}
				}
				goto again;
			}
		}
	return 0;
}