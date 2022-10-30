#include<iostream>
#include<algorithm>
#include<regex>
using namespace std;
double check(int);
int check1();
int check2();
int main() {                                    
	int size;                    //Define the size of array and check the defined limit of it
	do {
		size = check1();
	} while (size>20);
	double *array1 = new double[size];
	int i;                      //User is choosing mode to fill the array and also his entered number is checking
	int number2 = check2();     //Filling the array with the chosen mode
	switch (number2)  {
	case 1: {
		for (i = 0; i < size; i++) {
			array1[i] = check(i);
		}
		break;
	}
	case 2: {
		for (i = 0; i < size; i++) {
			array1[i] = rand();
		}
		break;
	}
	}
	int k1 = 0, k2 = 0, j = 0, t = 0; //Define coefficients of max and min meanings to make task
	for (i = 1; i < size; i++) {
		if (array1[i] < array1[0]) {    //Define min
			k1 = i;
		}
		else { k1 = 0; }
		if (array1[i] > array1[0]) {   //Define max
			k2= i;
		}
		else { k2 = 0; }
	}
	cout << "The elements in the array\n"; //If we don't fulfill a condition, the program restarts else it continues to complete a task
	for (i = 0; i <size; i++) {
			cout << array1[i] << " ";
		}
		cout << "\n";
		if (k2 > k1 || k2==k1) { cout << "Error. Max meaning is to the left than min meaning or you enter one element. Program is restarting\n";
		main();
		}
		else {
			for (i = k2+1; i<=k1; i++) {
				j = i;
				for (t = i; t<k1; t++) {
					if (array1[j] > array1[t]) {
						j = t;
					}
				}
				swap(array1[i], array1[j]);
			}
			cout << "\n";
			for (i = 0; i < size; i++) {
				cout << array1[i] << "\t";
			}
		}
	delete[] array1;
	return 0;
}
double check(int i) {
	string s2;
	regex b3("^[-]?""[0-9]{1}""[.]?""[0-9]*");
	regex b4("^[-]?""[1-9]+""[.]?""[0-9]*");
	regex b5("^[-]?""[0-9]{1}""[.]{1}");
	cout << "Enter the element [" << i + 1 << "] in the array (only numerical)\n";
	getline(cin, s2);
	while (!regex_match(s2, b3) && !regex_match(s2, b4) || regex_match(s2, b5)) {
		cout << "Error. This element is not numerical. Enter it [" << i + 1 << "] again\n";
		getline(cin, s2);
	}
	return stod(s2);
}
int check1() {
	string s1;
	regex b1("[0-9]{1}");
	regex b2("^[1-9]{1}""[0-9]+");
	do {
		cout << "Enter size of array from 1 to 20 (only integers)\n";
		getline(cin, s1);
	} while (!regex_match(s1, b1) && !regex_match(s1, b2));
	return stoi(s1);
}
int check2() {
	string number;
	regex number1("^[1-2]{1}");
	cout << "Choose the mode of filling the elements of array (random or manual). Please, enter only number\n";
	cout << "1. Manual\n";
	cout << "2. Random\n";
	getline(cin, number);
	while (!regex_match(number, number1)) {
		cout << "Please, enter only number\n";
		getline(cin, number);
	}
	return stoi(number);
}