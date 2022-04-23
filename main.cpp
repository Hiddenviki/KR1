#include <iostream>
#include "Circle.h"
#include "Circle_box.h"
using namespace std;

void showMenu(int* a){
    cout<<endl;

    cout << "____________________МЕНЮ____________________" << endl;
    cout << " 1.      Вывести всех кружочков" << endl;
    cout << " 2.      Добавить новый круг" << endl;
    cout << " 3.      Найти все окружности которые на ОХ" << endl;
    cout << " 4.      Найти все окружности которые на ОY" << endl;
    cout << " 5.      Сделать все на случайном массиве" << endl;
    cout << " 6.      Завершить аоао" << endl;
    cout<<endl;
    cout << "Введите число [1 , 6]" << endl;

    cin >> *(a);
    //CheckMenu();
}
int Circle::count = 0;

int main() {

    Circle_box element;
    double_massiv(element.Array);
    int a;
    do {
        showMenu(&a);
        switch (a) {
            case 1: //вывести то что написали щас
                element.showData();
                break;

            case 2: //добавить новый circle
                element.addElement();
                break;

            case 3: //task
                Search_OX(element.Array,Circle::count);
                break;
            case 4:
                Search_OY(element.Array,Circle::count);
                break;
            case 5:
                for_random(element.Array);
                break;
        }

    } while (a != 6);
}