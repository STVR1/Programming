#include<iostream>
using namespace std;
int main() {
	bool ping = true;
	int done = 0;
	double c = 0;
	do {
		char check[256];
		cout << "Enter number (double or integer)\n";
		cin.getline(check, 256);
		bool point = false;
		for (int i = 0; i < strlen(check); i++) {
			if (isdigit(check[i])) {
				done++;
			}
			else if ( i != 0  && i != (strlen(check) - 1) && check[i]=='.' && point==false) {
				done++;
				point = true;
			}
			else if (i==0 && check[i]=='-' && i != (strlen(check) - 1)) {
				done++;
			}
			else {
				cout << "Error\n";
				ping = false;
				break;
			}
			if (done == strlen(check)) {
				ping = true;
				break;
			}
		}
		c = atof(check);
		done = 0;
	} while (ping == false);
	cout << c;
	return 0;
}