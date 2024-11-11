#include <iostream>
#include <math.h>
#include <iomanip>
#include "ComplexNumbers.h"

using namespace std;


int main() {

    setlocale(LC_ALL, "Russian");

    double r1, im1, r2, im2;
    int choice = chois();

    try {
        if (choice == 6 || choice == 7) {
            // Ввод данных для одного числа
            cout << "Введите действительную и мнимую часть числа: ";
            cin >> r1 >> im1;
            ComplexNumber num1(r1, im1);

            switch (choice) {
            case 6: {
                cout << "Модуль числа: " << num1.modulus() << endl;
                break;
            }
            case 7: {
                cout << "Тригонометрическая форма числа: " << num1.trigonometric_form() << endl;
                break;
            }
            }
        }
        else {
            // Ввод данных для двух чисел
            cout << "Введите действительную и мнимую часть первого комплексного числа: ";
            cin >> r1 >> im1;

            cout << "Введите действительную и мнимую часть второго комплексного числа: ";
            cin >> r2 >> im2;

            ComplexNumber num1(r1, im1);
            ComplexNumber num2(r2, im2);

            switch (choice) {
            case 1: {
                ComplexNumber result = ComplexNumber::sum(num1, num2);
                cout << "Результат сложения: " << result.to_string() << endl;
                break;
            }
            case 2: {
                ComplexNumber result = ComplexNumber::sub(num1, num2);
                cout << "Результат вычитания: " << result.to_string() << endl;
                break;
            }
            case 3: {
                ComplexNumber result = ComplexNumber::multiply(num1, num2);
                cout << "Результат умножения: " << result.to_string() << endl;
                break;
            }
            case 4: {
                ComplexNumber result = ComplexNumber::divide(num1, num2);
                cout << "Результат деления: " << result.to_string() << endl;
                break;
            }
            case 5: {
                if (num1.is_equal(num2)) {
                    cout << "Комплексные числа равны." << endl;
                }
                else {
                    cout << "Комплексные числа не равны." << endl;
                }
                break;
            }
            }
        }
    }
    catch (const std::invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
