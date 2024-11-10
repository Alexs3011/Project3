#pragma once
#include <string>
#include <math.h>

using namespace std;
/// Класс - калькулятор двух комплексных чисел, где поле real - действительная часть числа, imagi - мнимая
class ComplexNumber {

private:
    double real;
    double imagi;

public:
    // Конструктор по умолчанию
    ComplexNumber() {
        real = 0;
        imagi = 0;
    }

    // Конструктор с параметрами
    ComplexNumber(double r, double im) {
        set_real(r);
        set_imagi(im);
    }

    /// Установка значения действительной части комплексного числа 
    void set_real(double r) { real = r; }

    /// Установка значения мнимой части комплексного числа 
    void set_imagi(double im) { imagi = im; }

    /// Получение значения действительной части комплексного числа
    double get_real() const { return real; }

    /// Получение значения мнимой части комплексного числа
    double get_imagi() const { return imagi; }

    /// Метод для получения строкового представления
    string to_string() const {
        return std::to_string(real) + " + " + std::to_string(imagi) + "i";
    }

    /// Метод для суммы 2 комплексных чисел, где num1, num2 - комплексные числа
    static ComplexNumber sum(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real + num2.real, num1.imagi + num2.imagi);
    }

    /// Метод для вычитания 2 комплексных чисел, где num1, num2 - комплексные числа
    static ComplexNumber sub(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real - num2.real, num1.imagi - num2.imagi);
    }

    /// Метод для умножения 2 комплексных чисел, где num1, num2 - комплексные числа
    static ComplexNumber multiply(const ComplexNumber& num1, const ComplexNumber& num2) {
        double r = (num1.real * num2.real) - (num1.imagi * num2.imagi);
        double im = (num1.real * num2.imagi) + (num1.imagi * num2.real);
        return ComplexNumber(r, im);
    }

    /// Метод для деления двух комплексных чисел, где num1, num2 - комплексные числа
    static ComplexNumber divide(const ComplexNumber& num1, const ComplexNumber& num2) {
        if (num2.real == 0 && num2.imagi == 0) {
            throw std::invalid_argument("Деление на ноль!");// Ошибка деления на ноль
        }

        // Сопряжённое к другому числу
        ComplexNumber conjugate(num2.real, -num2.imagi);

        // Умножаем числитель и знаменатель на сопряжённое
        ComplexNumber numerator = multiply(num1, conjugate);
        double denominator = multiply(num2, conjugate).real; // Действительная часть знаменателя

        return ComplexNumber(numerator.real / denominator, numerator.imagi / denominator);
    }

};

int chois() {
    int choise;
    cout << " Операции над комплексными числами\n";
    cout << "1 - Сложение\n";
    cout << "2 - Вычитание\n";
    cout << "3 - Умножение\n";
    cout << "4 - Деление\n";
    cout << "\n Выберите действие : \n";
    cin >> choise;
    return choise;
}