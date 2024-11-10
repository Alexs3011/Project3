#include <iostream>
#include <math.h>
#include <iomanip>
#include "ComplexNumbers.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "RU");
    double r, im;
    ComplexNumber res;

    cout << "Введите 2 комплексных числа" << endl;

    cout << "Введите 1 комплексное число(действительная мниммая)" << endl;
    cin >> r >> im;
    ComplexNumber num1(r, im);

    cout << "Введите 2 комплексное число(действительная мниммая)" << endl;
    cin >> r >> im;
    ComplexNumber num2(r, im);

    int choise;
    choise = chois();

    switch (choise) {
    case 1:
        res = ComplexNumber::sum(num1, num2);
        break;
    case 2:
        res = ComplexNumber::sub(num1, num2);
        break;
    case 3:
        res = ComplexNumber::multiply(num1, num2);
        break;
    case 4:
        res = ComplexNumber::divide(num1, num2);
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return 1; // Завершить программу с ошибкой
    }

    cout << res.to_string() << setprecision(2)  << endl;

    return 0;
}


