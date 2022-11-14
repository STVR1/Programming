#include<iostream>
#include<string>
#include<regex>
using namespace std;
int checkelement(int, int);
int check(string);
int choice();
int repite();
void algorithm(int**, int, int, int, int);
int main() {
	int repite1;
	do {
		//Set variables
		int n = 0, m = 0;
		string type;
		//Set the size of matrix and check it
		do {
			cout << "Enter the size of square matrix\n";
			n = check("rows");
			m = check("columns");
		} while (n != m);
		//New dynamic array
		int** array1;
		int i = 0, j = 0;
		array1 = new int* [n];
		//Fill the array with choosing mod and check elements if user have chosen the second mod
		for (i = 0; i <= (n - 1); i++) {
			array1[i] = new int[m];
		}
		switch (choice()) {
		case 1: {
			for (i = 0; i <= (n - 1); i++) {
				for (j = 0; j <= (m - 1); j++) {
					array1[i][j] = rand() % 201 + (-101);
				}
			}
			break;
		}
		case 2: {
			cout << "Enter elements a[i][j]\n";
			for (i = 0; i <= (n - 1); i++) {
				for (j = 0; j <= (m - 1); j++) {
					array1[i][j] = checkelement(i, j);
					cout << "a[" << i + 1 << "][" << j + 1 << "]=" << array1[i][j] << endl;
				}
			}
			break;
		}
		}
		//Just output the matrix
		for (i = 0; i <= (n - 1); i++) {
			cout << "| ";
			for (j = 0; j <= (m - 1); j++) {
				cout << " " << array1[i][j];
			}
			cout << " |";
			cout << "\n";
		}
		//Algorithm in separate function
		algorithm(array1, i, j, n, m);
		for (i = 0; i <= n - 1; i++) {
			delete[] array1[i];
		}
		delete[] array1;
		repite1 = repite();
	} while (repite1 == 1);
	return 0;
}
int check(string type) {
	string foo;
	regex b("^[1-9]{1}""[0-9]*$");
	cout << "Enter the number of " << type << "\n";
	getline(cin, foo);
	while (!regex_match(foo, b)) {
		cout << "Not a positive integer. Enter it again\n";
		getline(cin, foo);
	}
	return stoi(foo);
}
int checkelement(int i, int j) {
	string a;
	regex b1("^[-]?[1-9]+[0-9]*$");
	regex b2("^[-]?[0-9]{1}$");
	cout << "Enter a[" << i + 1 << "][" << j + 1 << "]";
	getline(cin, a);
	while (!regex_match(a, b1) && !regex_match(a, b2)) {
		cout << "Error. This element is not numerical. Enter it [" << i + 1 << "][" << j + 1 << "] again\n";
		getline(cin, a);
	}
	return stoi(a);
}
int choice() {
	string foo;
	regex check("[1-2]{1}");
	do {
		cout << "Choose the mod of filling the array\n";
		cout << "Attention! If you choose the first mod, the elements will be in the limit [-100;200] and only integers\n";
		cout << "If you choose the second mod, the elements can be as integers,as not integers\n";
		cout << "1. Random\n";
		cout << "2. Manual\n";
		getline(cin, foo);
	} while (!regex_match(foo, check));
	return stoi(foo);
}
void algorithm(int** array1, int i, int j, int n, int m) {
	double sum = 0, sum1 = 0, sum2 = 0, asum = 0, asum1 = 0, asum2 = 0;
	for (i = 0; i <= (n - 1); i++) {
		sum = 0; sum1 = 0; asum = 0; asum1 = 0;
		for (j = 0; j <= (m - 1); j++) {
			asum += array1[j][i];
			sum += array1[i][j];
			if (j == (m - 1)) {
				asum1 = asum;
				sum1 = sum;
				if (i == 0) {
					asum2 = asum1;
					sum2 = sum1;
				}
			}
		}
		if (i > 0 && (sum2 != sum1 || asum2 != asum1)) {
			cout << "Not a magic matrix\n";
			break;
		}
		if (i == (n - 1) && sum2 == sum1 && asum2 == asum1 && sum2==asum2) {
			cout << "This is a magic matrix\n";
		}
	}
}
int repite() {
	string foo;
	regex check("[1-2]{1}");
	do {
		cout << "Do you want to repite it. Press 1 if yes and press 2 if no\n";
		getline(cin, foo);
	} while (!regex_match(foo, check));
	return stoi(foo);
}