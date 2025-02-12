#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Проверка на то что вводится число
void noErrorInput(int& number,const string& str){
    while (true) {
        cout << str;
        if (cin >> number) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(2000, '\n');
            cout << "Введено не верное значение\n";
        }
    }
}

// Заполнение множества
void inputSet(set<int>& S)
{
    string line;
    while (true) 
    {
        getline(cin, line);

        bool all_spaces = true;
        for (char chr : line) {
            if (chr != ' ') {
                all_spaces = false;
                break;
            }
        }

        if (all_spaces || line.empty()) {
            cout << "Ничего не введено. Пожалуйста, повторите ввод." << endl;
        }
        else {
            istringstream stream(line);
            int num;

            while(stream >> num )
            {
                    S.insert(num);
            }
            if (S.empty())
            {
                cout << "Введенны не числа." << endl;
            }
            else { break; }
        }
    }
}

// Вывод множества
void printSet(set<int>& S)
{
    set<int>::iterator it;
    for (it = S.begin(); it!=S.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


// Определение выполняется ли равенство из задания
bool checkInequality(set<int>& A, set<int>& B)
{
    set<int> C, result;
    set<int>::iterator it;
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin())); // Ф-ия объединения
    cout << "Множество C: ";
    printSet(C);
    set_difference(C.begin(), C.end(), B.begin(), B.end(), inserter(result, result.end())); // Ф-ия разности
    cout << "Множество RES: ";
    printSet(result);
    return result == A;
}

int main()
{
    setlocale(LC_ALL, "ru");

    set<int> A, B;
    
    cout << "Введите множество A" << endl;;
    inputSet(A);
    
    cout << "Введите множество B: " << endl;
    inputSet(B);

    cout << "Множество A: ";
    printSet(A);
    cout << "Множество B: ";
    printSet(B);

    if (checkInequality(A, B)) { cout << "Высказывание правдиво" << endl; }
    else { cout << "Высказывание ложно"<<endl; }
}