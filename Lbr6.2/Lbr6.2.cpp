#include<iostream>
#include<conio.h>
using namespace std;
int main() {
	char string[256];
	int  x;
	cout << "Enter only 1 or 0\n";
	cin.getline(string, 256);
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
		while (string[i] != '1' && string[i] != '0') {
			cout << "Error. Your string has other elements. You must enter only 1 or 0. Enter it again\n";
			cin.getline(string, 256);
			len = strlen(string);
			
		}
	}
	cout << "Amount of groups with five elements\n";
	x = (int) strlen(string) / 5;
	cout << x;
	return 0;
}