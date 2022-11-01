#include<iostream>
#include<cmath>
#include<string>
#include<regex>
#include<conio.h>
using namespace std;
int enter(int);
int main() {
    setlocale(LC_ALL, "Rus");
    string z,d;
    regex b1("([\\digits]+)");
    regex b2("(\-)""([\\digits]+)");
    regex b3("(\-)""([\\digits]+)""(\.)""([\\digits]+)");
    regex b4("([\\digits]+)""(\.)""([\\digits]+)");
    regex b5("([1-3])");
    double x, f, y;
    int  key = 13;
    char a = 'a';
    cout << "Введите переменную z\n";
    getline(cin, z);
    enter(key);
    while (!regex_match(z, b1)
        && !regex_match(z, b2)
        && !regex_match(z, b3)
        && !regex_match(z, b4)){
        cin.clear();
        cin.ignore();
        cout << "Ошибка ввода! Введите повторно z\n";
        getline(cin, z);
        enter(key);
    }
    double z1 = stoi(z);
    if (z1 < 1) {
        x = pow(z1, 2);
        cout << "Вычисления проводились по ветке 1\n";
    }
    else {
        x = z1 + 1;
        cout << "Вычисления проводились по ветке 2\n";
    }
    do {
        cout << "Введите номер функции которая будет использоваться при вычислении\n";
        cout << "1. 2x\n";
        cout << "2. x в степени 2\n";
        cout << "3. x/3\n";
        getline(cin, d);
        enter(key);
    } while ( !regex_match(d, b5));
    int d1 = stoi(d);
    switch (d1) {
    case 1: f = 2 * x;
        cout << "Вычисления проводились с функцией 1\n";
        break;
    case 2: f = pow(x, 2);
        cout << "Вычисления проводились с функцией 2\n";
        break;
    case 3: f = x / 3;
        cout << "Вычисления проводились с функцией 3\n";
        break;
    }
    double intpart, fractpart;
    fractpart = modf(f + 1, &intpart);
    y = a * log(1 + pow(x, 0.2)) + pow(cos(intpart), 2);
    cout << "Значение вычисленного:\n" << y;
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