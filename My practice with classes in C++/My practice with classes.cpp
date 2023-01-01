#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<fstream>
using namespace std;

//Functions for choice the certain option

//Function for choosing task

int choice_task() {
    string choice;
    regex check1("^([1-3]{1})$");
    do {
        cout << "Choose the task" << endl;
        cout << "1. Task 1" << endl;
        cout << "2. Task 2" << endl;
        cout << "3. Task 3" << endl;
        getline(cin, choice);
    } while (!regex_match(choice, check1));
    return stoi(choice);
}                      

//Function for choosing operation

int choice_operation() {
    string choice;
    regex check1("^([1-2]{1})$");
    do {
        cout << "Do you want to fill your list or just check out certain information?" << endl;
        cout << "1. Fill" << endl;
        cout << "2. Check out" << endl;
        getline(cin, choice);
    } while (!regex_match(choice, check1));
    return stoi(choice);
}

//Function for choosing option (operation) for task3 only

int choice_option() {
    string choice;
    regex check("^([1-2]{1})$");
    do {
        cout << "Choose the operation with array" << endl;
        cout << "1. Creating" << endl;
        cout << "2. Transforming" << endl;
        getline(cin, choice);
    } while (!regex_match(choice,check));
    return stoi(choice);
}

//Function for choosing mod (reading from file or filling by yourself)

int choice_mod() {
    string choice;
    regex check("^([1-2]{1})$");
    do {
        cout << "Choose the mod" << endl;
        cout << "1. Reading from file" << endl;
        cout << "2. Filling by yourself" << endl;
        getline(cin, choice);
    } while (!regex_match(choice, check));
    return stoi(choice);
}

//Function for ennding this program, if user want to do it

int choice_ending(string foo) {
    string choice;
    regex check1("^([1-2]{1})$");
    do {
        cout << "Do you want to continue your work "<< foo << " ? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        getline(cin, choice);
    } while (!regex_match(choice, check1));
    return stoi(choice);
}

//All functions and class for Task1

//Class for task1

class Task1 {
public:
    vector<Task1> list1;
    void getData( int i, Task1 Action1);
    vector<Task1> filling();
    vector<Task1> reading1();
    void saving();
private:
    string brand, size_h, size_w, price;
};

//Function for getting data from list1 

void Task1::getData(int i, Task1 Action1) {
        cout << Action1.list1[i].brand << "\t" << Action1.list1[i].size_h << "\t" << Action1.list1[i].size_w << "\t" << Action1.list1[i].price << "\t" << endl;
};

//Function for filling list1 (adding function)

vector<Task1> Task1::filling() {
    string choice;
        regex check2("^([1-9]{1}[0-9]*)$");
        size_t size = list1.size();
        do {
            cout << "How many items do you want to add in your list. The current size is "<<list1.size() << endl;
            getline(cin, choice);
        } while (!regex_match(choice, check2));
        list1.resize(stoi(choice)+size);
        for (int i = size; i < size+stoi(choice); i++) {
            cout << "The " << i + 1 << "-st is current" << endl;
            cout << "Input brand" << endl;
            getline(cin, list1[i].brand);
            cout << "Input size_h" << endl;
            getline(cin, list1[i].size_h);
            cout << "Input size_w" << endl;
            getline(cin, list1[i].size_w);
            cout << "Input price" << endl;
            getline(cin, list1[i].price);
        }
        return list1;
}

//Function for reading list for task1 from file

vector<Task1> Task1::reading1() {
    ifstream document;
    string path, temp, needed;
    size_t size = list1.size();
    int k = 1, f = 1, point=1;
    regex checking("^([A-Za-z0-9[:space:]]+)(:){1}([\\\\]{1}[A-Za-z0-9[:space:]]+|([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt)){1})+$");
    do {
        cout << "Input the path to your document with .txt expansion" << endl;
        getline(cin, path);
    } while (!regex_match(path, checking));
    document.open(path);
    if (document.is_open()) {
        while (getline(document, temp)) {
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == ' ' && needed.size()!=0) {
                    if (point == 1) {
                        list1.resize(k+size);
                        list1[k+size - 1].brand = needed;
                        point++, f=1;
                        needed.resize(0);
                    }
                    else if (point == 2) {
                        list1[k+size - 1].size_h = needed;
                        point++, f=1;
                        needed.resize(0);
                    }
                    else if (point == 3) {
                        list1[k+size - 1].size_w = needed;
                        point++, f=1;
                        needed.resize(0);
                        
                    }
                    else if (i == temp.size() - 1 && point == 4) {
                        list1[k + size - 1].price = needed;
                        point = 1, f = 1, k++;
                        needed.resize(0);
                    }
                }
                else if (temp[i]!=' ') {
                    needed.resize(f);
                    needed[f-1] = temp[i];
                    f++;
                    if (i == temp.size() - 1 && point == 4) {
                    list1[k + size - 1].price = needed;
                    point = 1, f = 1, k++;
                    needed.resize(0);
                    }
                }
            }
        }
        cout << "Successfully read" << endl;
    }
    else {
        cout << "Error. Can't open document" << endl;
        cout << "Reading denied" << endl;
    }
    document.close();
    return list1;
}

//Function for saving list of task1 into certain file

void Task1::saving() {
    ofstream document;
    string path;
    regex checking("^([A-Za-z0-9[:space:]]+)(:){1}([\\\\]{1}[A-Za-z0-9[:space:]]+|([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt)){1})+$");
    do {
        cout << "Input the path to file, which will be used for save" << endl;
        getline(cin, path);
    } while (!regex_match(path, checking));
    document.open(path);
    if (document.is_open()) {
        for (int i = 0; i < list1.size(); i++) {
            document << list1[i].brand << "\t";
            document << list1[i].size_h << "\t";
            document << list1[i].size_w << "\t";
            document << list1[i].price<<"\t" << endl;
        }
        cout << "Successfully saved into " << path << ""<<endl;
    }
    else {
        cout << "Error. Can't open document" << endl;
        cout << "Saving denied" << endl;
    }
    document.close();
}

//The main function for completing task1

vector<Task1> task1(Task1 Action1) {
    do {
        if (choice_operation() == 1) {
            if (choice_mod() == 1) {
                Action1.list1 = Action1.reading1();
            }
            else {
                Action1.list1 = Action1.filling();
            }
        }
        else {
            if (Action1.list1.size() == 0) {
                cout << "Error. Your list doesn't consist info" << endl;
            }
            else {
                cout << "Brand" << "\t" << "Size_h" << "\t" << "Size_w" << "\t" << "Price" << "\t" << endl;
                for (int i = 0; i < Action1.list1.size(); i++) {
                    Action1.list1[i].getData(i, Action1);
                }
            }
        }
    } while (choice_ending("with this task") != 2);
    string choice;
    regex check1("^([1-2]{1})$");
    do {
        cout << "Do you want to save all changes into certain file?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. Not" << endl;
        getline(cin, choice);
    } while (!regex_match(choice, check1));
    if (choice == "1") {
        Action1.saving();
    }
    return Action1.list1;
}

//All functions and class for Task2

//Class for task2

class Task2 {
public:
    vector<Task2> list2;
    void getData(int i, Task2 Action2);
    vector<Task2> filling();
    vector<Task2> reading2();
    void saving();
private:
    string fname, sname, age;
};

//Function for getting data from list2 

void Task2::getData(int i, Task2 Action2) {
    cout << Action2.list2[i].fname << "\t" << Action2.list2[i].sname << "\t" << Action2.list2[i].age << "\t" << endl;
}

//Function for filling list2 (adding function)

vector<Task2> Task2::filling() {
    string choice;
    regex check2("^([1-9]{1}[0-9]*)$");
    size_t size = list2.size();
    do {
        cout << "How many items do you want to add in your list. The current size is " << list2.size() << endl;
        getline(cin, choice);
    } while (!regex_match(choice, check2));
    list2.resize(stoi(choice) + size);
    for (int i = size; i < size + stoi(choice); i++) {
        cout << "The " << i + 1 << "-st is current" << endl;
        cout << "Input the first name" << endl;
        getline(cin, list2[i].fname);
        cout << "Input the second name" << endl;
        getline(cin, list2[i].sname);
        cout << "Input age" << endl;
        getline(cin, list2[i].age);
    }
    return list2;
}

//Function for reading list for task2 from file

vector<Task2> Task2::reading2() {
    ifstream document;
    string path, temp, needed;
    size_t size = list2.size();
    int k = 1, f = 1, point = 1;
    regex checking("^([A-Za-z0-9[:space:]]+)(:){1}([\\\\]{1}[A-Za-z0-9[:space:]]+|([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt)){1})+$");
    do {
        cout << "Input the path to your document with .txt expansion" << endl;
        getline(cin, path);
    } while (!regex_match(path, checking));
    document.open(path);
    if (document.is_open()) {
        while (getline(document, temp)) {
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == ' ' && needed.size() != 0) {
                    if (point == 1) {
                        list2.resize(k + size);
                        list2[k + size - 1].fname = needed;
                        point++, f = 1;
                        needed.resize(0);
                    }
                    else if (point == 2) {
                        list2[k + size - 1].sname = needed;
                        point++, f = 1;
                        needed.resize(0);
                    }
                    if (i == temp.size() - 1 && point == 3) {
                        list2[k + size - 1].age = needed;
                        point = 1, f = 1, k++;
                        needed.resize(0);
                    }
                }
                else if (temp[i] != ' ') {
                    needed.resize(f);
                    needed[f - 1] = temp[i];
                    f++;
                    if (i == temp.size() - 1 && point == 3) {
                        list2[k + size - 1].age = needed;
                        point = 1, f = 1, k++;
                        needed.resize(0);
                    }
                }
            }
        }
        cout << "Successfully read" << endl;
    }
    else {
        cout << "Error. Can't open document" << endl;
        cout << "Reading denied" << endl;
    }
    document.close();
    return list2;
}

//Function for saving list of task2 into certain file

void Task2::saving() {
    ofstream document;
    string path;
    regex checking("^([A-Za-z0-9[:space:]]+)(:){1}([\\\\]{1}[A-Za-z0-9[:space:]]+|([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt)){1})+$");
    do {
        cout << "Input the path to file, which will be used for save" << endl;
        getline(cin, path);
    } while (!regex_match(path, checking));
    document.open(path);
    if (document.is_open()) {
        for (int i = 0; i < list2.size(); i++) {
            document << list2[i].fname << "\t";
            document << list2[i].sname << "\t";
            document << list2[i].age << "\t" << endl;;
        }
        cout << "Successfully saved into " << path << "" << endl;
    }
    else {
        cout << "Error. Can't open document" << endl;
        cout << "Saving denied" << endl;
    }
    document.close();
}

//The main function for completing task2

vector<Task2> task2(Task2 Action2) {
    do {
        if (choice_operation() == 1) {
            if (choice_mod() == 1) {
                Action2.list2 = Action2.reading2();
            }
            else {
                Action2.list2 = Action2.filling();
            }
        }
        else {
            if (Action2.list2.size() == 0) {
                cout << "Error. Your list doesn't consist info" << endl;
            }
            else {
                cout << "The first name" << "\t" << "The second name" << "\t" << "Age" << "\t" << endl;
                for (int i = 0; i < Action2.list2.size(); i++) {
                    Action2.list2[i].getData(i, Action2);
                }
            }
        }
    } while (choice_ending("with this task") != 2);
    string choice;
    regex check1("^([1-2]{1})$");
    do {
        cout << "Do you want to save all changes into certain file?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. Not" << endl;
        getline(cin, choice);
    } while (!regex_match(choice, check1));
    if (choice == "1") {
        Action2.saving();
    }
    return Action2.list2;
}

//All functions and class for Task3 

//Class for task3

class Task3 {
public:
    int** array=new int*[0];
    int n = 0, m = 0;
    int** creating_array();
    int** transforming_array();
    int** reading3();
    void saving();
};

//Two functions for defining size of array

int size_rows() {
    string n;
    regex check("^([1-9]{1}[0-9]*)$");
    cout << "Enter the number of rows" << endl;
    getline(cin, n);
    while (!regex_match(n, check)) {
        cout << "Error. Enter it again" << endl;
        getline(cin, n);
    }
    return stoi(n);
}

int size_columns() {
    string m;
    regex check("^([1-9]{1}[0-9]*)$");
    cout << "Enter the number of columns" << endl;
    getline(cin, m);
    while (!regex_match(m, check)) {
        cout << "Error. Enter it again" << endl;
        getline(cin, m);
    }
    return stoi(m);
}

//Function for creating array

int** Task3::creating_array(){
    regex check("^([-]?[1-9]{1}[0-9]*)|([0]{1})$");
    string temp;
    array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            do {
                cout << "Enter the element [" << i + 1 << "][" << j + 1 << "]: ";
                getline(cin, temp);
                cout << endl;
            } while (!regex_match(temp, check));
            array[i][j] = stoi(temp);
        }
    }
    return array;
}

//Function for array's transformation

int** Task3::transforming_array() {
    int** temp_array = new int* [m];
    for (int i = 0; i < m; i++) {
        temp_array[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp_array[j][i] = array[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
    return temp_array;
}

//Function for reading array from file

int** Task3::reading3(){
    ifstream document;
    string path, temp, needed;
    vector<string> rubbish;
    int k = 1, f = 1, point = 0;
    regex checking("^([A-Za-z0-9[:space:]]+)(:){1}([\\\\]{1}[A-Za-z0-9[:space:]]+|([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt)){1})+$");
    do {
        cout << "Input the path to your document with .txt expansion" << endl;
        getline(cin, path);
    } while (!regex_match(path, checking));
    document.open(path);
    if (document.is_open()) {
        while (getline(document, temp)) {
            rubbish.resize(k);
            rubbish[k - 1] = temp;
            k++;
        }
    }
    else {
        cout << "Error. Can't open document" << endl;
        cout << "Reading denied" << endl;
        return array;
    }
    document.close();
    n = rubbish.size();
    k = 1;
    for (int j = 0; j < rubbish[0].size(); j++) {
        if (rubbish[0][j] == ' ' && needed.size() != 0) {
            point++;
        }
        else if (rubbish[0][j] != ' ') {
            needed.resize(k);
            k ++ ;
            if (j == rubbish[0].size() - 1) {
                point++;
            }
        }
    }
    m = point;
    array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    point = 0, k=1;
    needed.resize(0);
    for (int i = 0; i < rubbish.size(); i++) {
        for (int j = 0; j < rubbish[i].size(); j++) {
            if (rubbish[i][j] == ' ' && needed.size() != 0) {
                array[i][point] = stoi(needed);
                point++, k=1;
                needed.resize(0);
            }
            else if (rubbish[i][j] != ' ') {
                needed.resize(k);
                needed[k - 1] = rubbish[i][j];
                k++;
                if (j == rubbish[i].size() - 1) {
                    array[i][point] = stoi(needed);
                    point=0, k = 1;
                    needed.resize(0);
                }
            }
        }
    }
    cout << "Successfully read" << endl;
    return array;
}

//Function for saving array into certain file

void Task3::saving() {
    ofstream document;
    string path;
    regex checking("^([A-Za-z0-9[:space:]]+)(:){1}([\\\\]{1}[A-Za-z0-9[:space:]]+|([\\\\]{1}[A-Za-z0-9[:space:]]+(.txt)){1})+$");
    do {
        cout << "Input the path to file, which will be used for save" << endl;
        getline(cin, path);
    } while (!regex_match(path, checking));
    document.open(path);
    if (document.is_open()) {
        for (int i = 0; i < (_msize(array) / sizeof(int)) / 2; i++) {
            for (int j = 0; j < _msize(array[0]) / sizeof(int); j++) {
                if (j == _msize(array[0]) / sizeof(int)-1) {
                    document << array[i][j];
                }
                else {
                    document << array[i][j]<<" ";
                }
            }
            document  << endl;
        }
        cout << "Successfully saved into " << path << "" << endl;
    }
    else {
        cout << "Error. Can't open document" << endl;
        cout << "Saving denied" << endl;
    }
    document.close();
}

//The main function for completing task3 

int** task3(Task3 Action3) {
    int temp = 0;
    do {
        if (choice_option() == 1) {
            if (Action3.n != 0 && Action3.m != 0) {
                cout << "Previous was deleted" << endl;
                for (int i = 0; i < Action3.n; i++) {
                    delete[] Action3.array[i];
                }
                delete[] Action3.array;
            }
            if (choice_mod() == 1) {
                Action3.array = Action3.reading3();
            }
            else {
                Action3.n = size_rows();
                Action3.m = size_columns();
                Action3.array = Action3.creating_array();
            }
        }
        else {
            if (Action3.n==0 && Action3.m==0) {
                cout << "Your array isn't created" << endl;
                 return Action3.array;
            }
            else {;
                cout << "Your array before transformation" << endl;
                for (int i = 0; i < Action3.n; i++) {
                    for (int j = 0; j < Action3.m; j++) {
                        cout << Action3.array[i][j] << " ";
                    }
                    cout << endl;
                }
                Action3.array = Action3.transforming_array();
                temp = Action3.n;
                Action3.n = Action3.m;
                Action3.m = temp;
                cout << "Your array after transformation" << endl;
                for (int i = 0; i < Action3.n; i++) {
                    for (int j = 0; j < Action3.m; j++) {
                        cout << Action3.array[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    } while (choice_ending("with this task") == 1);
    string choice;
    regex check1("^([1-2]{1})$");
    do {
        cout << "Do you want to save all changes into certain file?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. Not" << endl;
        getline(cin, choice);
    } while (!regex_match(choice, check1));
    if (choice == "1") {
        Action3.saving();
    }
    return Action3.array;
}

//The main function, which fulfill all tasks according to user's choice

int main() {
    Task1 Action1;
    Task2 Action2;
    Task3 Action3;
    do {
        switch (choice_task()) {
        case 1: {
            Action1.list1 = task1( Action1);
            break;
        }
        case 2: {
            Action2.list2 = task2( Action2);
            break;
        }
        case 3: { 
            Action3.array = task3(Action3);
            if (_msize(Action3.array) != 0) {
                Action3.n = (_msize(Action3.array) / sizeof(int)) / 2; //I don't return meanings n and m after actions
                Action3.m = _msize(Action3.array[0]) / sizeof(int);    //with array. As a reason I define them using array
            }
            break;
        }
        }
    } while (choice_ending("with program") == 1);
    if (_msize(Action3.array) != 0) {
        for (int i = 0; i < (_msize(Action3.array) / sizeof(int)) / 2; i++) {
            delete[] Action3.array[i];
        }
        delete[] Action3.array;
    }
    else {
        delete[] Action3.array;
    }
    return 0;
}