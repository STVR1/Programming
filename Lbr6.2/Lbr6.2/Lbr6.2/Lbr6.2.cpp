#include<iostream>
#include<string>
#include<regex>
using namespace std;
int main() {
	string a;
	regex b("[0-1]+");
	do {
		cout << "Fill the line using ones and zeros only\n";
		getline(cin, a);
	} while (!regex_match(a, b));
	regex group("[0-1]{5}");
	cout << "Number of groups with five digits is ";
	cout <<distance(sregex_iterator(a.begin(), a.end(), group), sregex_iterator());
	return 0;
}