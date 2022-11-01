#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<conio.h>
#include<sstream> 
using namespace std;
int factorial(int);
float yfunc(float);
float sfunc(int, float, int, int,   int,float,float,float);
float dfunc(int , float , int , int , int , float , float , float);
float check(char,string,float);
float Out_Rez(int , int , float , int , int , int , float , float , float );
int main() {
	setlocale(LC_ALL, "Rus");
	string a, b, h, n, foo;
	char fo;
	float foo1=0;
	float a1, b5, h1, x;
	int k = 0, k1, n1 = 0;
	a1=check('a',a, foo1);
	b5=check('b',b, foo1);
	h1=check('h',h, foo1);
	cout << "Введите натуральное число n\n";
	getline(cin,n);
	regex b3("^[1-9]{1}""[0-9]*");
	stringstream s1;
	s1 << n;
	float n2;
	s1 >> n2;
	k1 = 1;
	x = a1;
	string key1;
	regex b4("[1-3]{1}");
	string key3;
	int key4;
	regex b6("[1-2]{1}");
	do {
		do {
			cout << "Выберите номер функции, которую вы хотите расчитать:" << endl;
			cout << "1. Y(x)=sin(x)" << endl;
			cout << "2. S(x)=(k=0)Z(n) (-1)^k * x^(2k+1):(2k+1)!" << endl;
			cout << "3. |Y(x)-S(x)|" << endl;
			getline(cin, key1);
		} while (!regex_match(key1, b4));
		stringstream s2;
		s2 << key1;
		int key;
		s2 >> key;
		Out_Rez(key, k, x, n1, n2, k1, a1, b5, h1);
		do {
			cout << "Do you want to make one more operation? Enter 1 if yes and enter 2 to exit\n";
			getline(cin, key3);
		} while (!regex_match(key3, b6));
		key4 = stoi(key3);
	} while (key4==1);
	return 0;
}
int factorial(int n1) {
	if (n1 == 0) return 1;
	if (n1 == 1) return 1;
	return n1 * factorial(n1 - 1);
}
float sfunc(int k, float x, int n1,  int n2,  int k1, float a1, float b5, float h1) {
	float s = 0, sum = 0, difference = 0;
	for (k1 = 1, x = a1; x <= b5; k1++, x += h1) {
		for (k = 0, sum = 0; k <= n2 - 1; k++) {
			yfunc(x);
			n1 = 2 * k + 1;
			s = pow(-1, k) * pow(x, 2 * k + 1) / factorial(n1);
			sum += s;
			difference = fabs(yfunc(x) - sum);
		}
		cout << k1 << "." << "\t" << x << "\t" << yfunc(x) << "\t" << sum  <<"\t" << endl;
	}
	return sum;
}
float yfunc(float x) {
	return sin(x);
}
float check(char fo, string foo,float foo1) {
	regex b1("^[-]?[0-9]+[.]?[0-9]*");
	regex b2("^[-]?[0-9]+[.]{1}");
	do {
		cout << "Введите действительное число "<<fo<<":\n";
		getline(cin, foo);
	} while (!regex_match(foo, b1) || regex_match(foo, b2));
	stringstream s;
	s << foo;
	s >> foo1;
	return foo1;
}
float Out_Rez(int key, int k, float x, int n1, int n2, int k1, float a1, float b5, float h1) {
	switch (key) {
	case 1: {
		cout << "x" <<"\t" << "Y(x)" << "\t" << endl;
		cout << x << "\t" <<yfunc(x) << "\t" <<endl;
		return yfunc(x);
	}
	case 2: {
		cout << "Number" << "\t" << "x" << "\t" << "Y(x)" << "\t" << "S(x)"  << "\t" << endl;
		return sfunc( k,  x,  n1,  n2,  k1,  a1,  b5,  h1);
	}
	case 3: {
		cout << "Number" << "\t" << "x" << "\t" << "Y(x)" << "\t" << "S(x)" << "\t" << "|Y(x)-S(x)|" << "\t" << endl;
		return dfunc(k, x,  n1,  n2,  k1,  a1,  b5,  h1);
	}
	}
}
float dfunc(int k, float x, int n1, int n2, int k1, float a1, float b5, float h1) {
	float s = 0, sum = 0, difference = 0;
	for (k1 = 1, x = a1; x <= b5; k1++, x += h1) {
		for (k = 0, sum = 0; k <= n2 - 1; k++) {
			yfunc(x);
			n1 = 2 * k + 1;
			s = pow(-1, k) * pow(x, 2 * k + 1) / factorial(n1);
			sum += s;
			difference = fabs(yfunc(x) - sum);
		}
		
		cout << k1 << "." << "\t" << x << "\t" << yfunc(x) << "\t" << sum << "\t" << difference << "\t" << endl;
	}
	return difference;
}