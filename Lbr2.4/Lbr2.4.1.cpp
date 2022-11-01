#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<conio.h>
using namespace std;
int enter(int);
int main() {
    setlocale(LC_ALL, "Rus");
    string k, z;
    regex b1("([\\digit]+)");
    regex b2("(\-)""([\\digit]+)");
    regex b3("(\-)""([\\digit]+)""(\.)""([\\digit]+)");
    regex b4("([\\digit]+)""(\.)""([\\digit]+)");
    long double x,y,t;
    int key = 13;
    cout << "Введите переменную k\n";
    getline(cin, k);
    enter(key);
    while (!regex_match(k, b1)
        && !regex_match(k, b2)
        && !regex_match(k, b3)
        && !regex_match(k, b4) ) {
        cin.clear();
        cin.ignore();
        cout << "Ошибка ввода! Введите повторно k\n";
        getline(cin, k);
        enter(key);
    }
    cout << "Введите переменную z\n";
    getline(cin, z);
    enter(key);
    while (!regex_match(z, b1)
        && !regex_match(z, b2)
        && !regex_match(z, b3)
        && !regex_match(z, b4)) {
        cin.clear();
        cin.ignore();
        cout << "Ошибка ввода! Введите повторно z\n";
        getline(cin, z);
        enter(key);
    }
    double k1 = stoi(k);
    double z1 = stoi(z);
    if (k1 < 1) {
        x = k1 * pow(z1, 3);
        cout << "Вычисления проводились по пути 1\n";
    }
    else {
        x = z1 * (z1 + 1);
        cout << "Вычисления проводились по пути 2\n";
    }
    t = log(1 + pow(x, 2)) + cos(x + 1);
    y = pow(t, exp(k1 * x));
    cout << y << endl;
    return 0;
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