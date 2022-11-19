#include <iostream>
#include<string>
#include<regex>
using namespace std;
int main()
{
    string a;
    regex b("^[-]?([1-9]{1}[0-9]+|[0-9]{1})((.[0-9]+)?)$");
    cout << "Enter string a\n";
    getline(cin, a);
    while (!regex_match(a, b)) {
        cout << "Error. Input it again\n";
        getline(cin, a);
    }
    double a1 = stod(a);
    cout << a1;
    return 0;
}