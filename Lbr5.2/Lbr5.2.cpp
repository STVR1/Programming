#include<iostream>
#include<string>
#include<regex>
#include<vector>
using namespace std;
int check(string , string , int );
double checkelement(string , double*, int , int  );
int check2(string , string, int , int );
int main() {
	int n=0, m=0, foo1=0, foo2=0;
	string foo,type;
	cout << "Enter the size of matrix\n";
	n=check("rows", foo, foo1);
	m=check("columns", foo, foo1);
	double** array1;
	int i=0,j=0;
	array1= new double *[n];
	for (i = 0; i <= (n-1); i++) {
		array1[i] = new double[m];
	}
	string a;
	double* a1 = new double;
	cout << "Enter elements a[i][j]\n";
	for (i = 0; i <= (n - 1); i++) {
		for (j = 0; j <= (m - 1); j++) {
			array1[i][j] = checkelement(a, a1, i, j);
			cout << "a[" << i + 1 << "][" << j + 1 << "]=" << array1[i][j] << endl;
		}
	}
	vector<double> B;
	int choice=check2(foo, "row", foo1, n);
	
	int k=check2(foo, "column", foo1, m);
	int reg = 0;
	cout << "\n";
	cout << "{ ";
	for (j = 0; j <= m - 1; j++) {
		B.push_back(array1[choice - 1][j]);
		if (j == (k-1)) {
			for (i = 0; i <= (n - 1); i++) {
				if (array1[i][k -1] == 0) {
					reg++;
				}
				if (i == (n - 1) && reg == n) {
					B[j] = 0;
				}
				else { B[j] = 1; }
			}
		}
		cout << B[j] << " ";
	}
	cout << " }";
	for (i = 0; i <= n - 1; i++) {
		delete[]array1[i];
	}
	delete a1;
	delete[] array1;
	return 0;
}
int check(string type,string foo, int foo1) {
	regex b("^[1-9]{1}""[0-9]*");
	
	cout << "Enter the number of "<<type<<"\n";
	getline(cin, foo);
	while (!regex_match(foo, b)) {
		cout << "Not a positive integer. Enter it again\n";
		getline(cin, foo);
	}
	foo1 = stoi(foo);
	return foo1;
}
double checkelement(string a, double*a1, int i, int j) {
	regex b3("^[-]?""[0-9]{1}""[.]?""[0-9]*");
	regex b4("^[-]?""[1-9]+""[.]?""[0-9]*");
	regex b5("^[-]?""[0-9]{1}""[.]{1}");
			cout << "Enter a[" << i + 1 << "][" << j + 1 << "]";
			getline(cin, a);
			while (!regex_match(a, b3) && !regex_match(a, b4) || regex_match(a, b5)) {
				cout << "Error. This element is not numerical. Enter it [" << i + 1 << "][" << j + 1 << "] again\n";
				getline(cin, a);
			}
			*a1 = stod(a);
	return *a1;
}
int check2(string foo,string type, int foo1,int foo2) {
	regex b("^[1-9]{1}""[0-9]*");
	do {
		cin.clear();
		cin.ignore();
		do {
			cout << "Enter the number of "<<type<<" you want to get the vector from. (Press enter one more time if the first press didn't work)\n";
			getline(cin, foo);
		} while (!regex_match(foo, b));
		foo1 = stoi(foo);
	} while (foo1 > foo2);
	return foo1;
}