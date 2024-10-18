//Сафошин А.С.

#include <iostream>
#include "calculate_cube.h" //Подключение заголовочного файла

using namespace std;// Подключаем пространство имён

int main()
{
    setlocale(LC_ALL, "RU");//Подключаем русский язык
    test();
    float len = 0, sqare = 0, value = 0;// Описание переменных
    cout << "Введите длину ребра куба: ";
    cin >> len;
    sqare = calculate_sqare(len); // Вызываем функции для подсчёта объёма и площади
    value = calculate_value(len);
    cout << "Площадь куба = " << sqare << ", а объём = " << value;// Выводим результат
}
