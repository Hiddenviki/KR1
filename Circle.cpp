
#include <iostream>
#include "Circle.h"
#include "StreamTable.h"
#include <cstdlib> // нужен для вызова функций rand(), srand()
#include <ctime> // нужен для вызова функции time()

using namespace std;

double CheckX()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Значение Х: ";
        double a;
        cin >> a;

        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

double CheckY()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Значение Y: ";
        double a;
        cin >> a;

        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

double CheckRadius()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Значение радиуса: ";
        double a;
        cin >> a;

        if (cin.fail() or (a <= 0)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout<<"радиус должен быть положительным числом"<<"\n";
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

bool on_OX(Circle Obj)
{
    if (Obj.get_center_y()==0){
        return true;
    }
    else {return false;}
}
bool on_OY(Circle Obj)
{
    if (Obj.get_center_x()==0){
        return true;
    }
    else {return false;}
}

void setData(Circle* Obj, int amount)
{
    Obj[amount].set_center_x(CheckX());
    Obj[amount].set_center_y(CheckY());
    Obj[amount].set_radius(CheckRadius());
}

void Search_OX(Circle* Obj, int amount)
{

    StreamTable st(std::cout);
    st.AddCol(5);
    st.AddCol(5);
    st.AddCol(5);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    st << "RADIUS" << "X" << "Y";
    bool no_any = true; //такой флаг для того, чтоб определить ненаход объекта

    for (int i = 0; i < Circle::count; i++)
    {
        if (on_OX(Obj[i]))
        {
            st << Obj[i].get_radius() << Obj[i].get_center_x() << Obj[i].get_center_y();
            no_any = false;
        }
    }
    if (no_any)
    {
        st << "radius"  << "x" << "y";
        cout<<"нет таких "<<endl;
    }
} //найти все товары заданной секции
void Search_OY(Circle* Obj, int amount)
{

    StreamTable st(std::cout);
    st.AddCol(5);
    st.AddCol(5);
    st.AddCol(5);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    st << "RADIUS" << "X" << "Y";
    bool no_any = true; //такой флаг для того, чтоб определить ненаход объекта

    for (int i = 0; i < Circle::count; i++)
    {
        if (on_OY(Obj[i]))
        {
            st << Obj[i].get_radius() << Obj[i].get_center_x() << Obj[i].get_center_y();
            no_any = false;
        }
    }
    if (no_any)
    {
        st << "radius"  << "x" << "y";
        cout<<"нет таких "<<endl;
    }
} //найти все товары заданной секции

void double_massiv(Circle* Obj) {
    int x[5];
    int y[5];
    int r[5];
    srand(time(nullptr)); // инициализация генерации случайных чисел


    for (int i = 0; i < 5; i++) {
        x[i] = -10 + rand() % 10;
        y[i] = -10 + rand() % 10;
        r[i] = 1 + rand() % 10; //радиус типа положительный
    }

    ///////то что должно быть в таблице///////
    for (int i: r) { cout << i << " \t"; }
    cout << "\n";
    for (int i: x) { cout << i << " \t"; }
    cout << "\n";
    for (int i: y) { cout << i << " \t"; }
    cout << "\n";
    ///////то что должно быть в таблице///////

    for (int i = 0; i < 5; i++) {
        Circle::count += 1;
        Obj[i].set_center_x(x[i]);
        Obj[i].set_center_y(y[i]);
        Obj[i].set_radius(r[i]);
    }

    StreamTable st(std::cout);
    st.AddCol(10);
    st.AddCol(10);
    st.AddCol(10);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    st << "RADIUS" << "X" << "Y";
    for (int i = 0; i < Circle::count; i++)
    {
        st << Obj[i].get_radius() << Obj[i].get_center_x() << Obj[i].get_center_y();
    }
}

void for_random(Circle* Obj)
{
    int x[5];
    int y[5];
    int r[5];
    srand(time(nullptr)); // инициализация генерации случайных чисел
    for (int i = 0; i < 5; i++)
    {
        x[i] = 0 + rand() % 4; //по ТЕорИИ шанс выпадения нуля как раз 1/5 я хочу чтоб он где-то хотя бы был
        y[i] = 0 + rand() % 4;
        r[i] = 1 + rand() % 5; //радиус типа положительный
    }

    StreamTable st(std::cout);
    st.AddCol(7);
    st.AddCol(7);
    st.AddCol(5);
    st.AddCol(5);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    cout<<"Вот рандомные данные:"<<endl;
    st <<"NUMBER"<< "RADIUS" << "X" << "Y";

    for (int i = 0; i < 5; i++){st <<i+1<< r[i] << x[i] << y[i];} //просто вывожу на экран

    for (int i = 0; i < 5; i++){
        if ((x[i]==0) and (y[i]!=0)){
            cout<<"Круг № "<<i+1<<" на оси ОУ"<<endl;
        }
        else if ((x[i]!=0) and (y[i]==0)){
            cout<<"Круг № "<<i+1<<" на оси ОX"<<endl;
        }
        else if ((x[i]==0) and (y[i]==0)){
            cout<<"Круг № "<<i+1<<" в центре координатной оси"<<endl;
        }
        else{
            cout<<"Круг № "<<i+1<<" не лежит на осях"<<endl;
        }
    }


}

