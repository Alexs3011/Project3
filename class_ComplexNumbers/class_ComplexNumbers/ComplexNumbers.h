#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cassert>

using namespace std;

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

    // Установка значения действительной части
    void set_real(double r) { real = r; }

    // Установка значения мнимой части
    void set_imagi(double im) { imagi = im; }

    // Получение значения действительной части
    double get_real() const { return real; }

    // Получение значения мнимой части
    double get_imagi() const { return imagi; }


    // Ключевое слово static используется для создания методов, которые будут существовать независимо от каких-либо экземпляров, созданных для класса.
    // Метод для получения строкового представления
    string to_string() const {
        string s;
        s = std::to_string(real) + (imagi >= 0 ? " + " : " - ") + std::to_string(abs(imagi)) + "i";
        return s;
    }

    
    // Метод для сложения двух комплексных чисел
    static ComplexNumber sum(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real + num2.real, num1.imagi + num2.imagi);
    }

    // Метод для вычитания двух комплексных чисел
    static ComplexNumber sub(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real - num2.real, num1.imagi - num2.imagi);
    }

    // Метод для умножения двух комплексных чисел
    static ComplexNumber multiply(const ComplexNumber& num1, const ComplexNumber& num2) {
        double r = (num1.real * num2.real) - (num1.imagi * num2.imagi);
        double im = (num1.real * num2.imagi) + (num1.imagi * num2.real);
        return ComplexNumber(r, im);
    }

    // Метод для деления двух комплексных чисел
    static ComplexNumber divide(const ComplexNumber& num1, const ComplexNumber& num2) {
        if (num2.real == 0 && num2.imagi == 0) {
            throw invalid_argument("Деление на ноль!");
        }
        ComplexNumber conjugate(num2.real, -num2.imagi);
        ComplexNumber numerator = multiply(num1, conjugate);
        double denominator = multiply(num2, conjugate).real;
        return ComplexNumber(numerator.real / denominator, numerator.imagi / denominator);
    }

    // Метод для вычисления модуля комплексного числа
    double modulus() const {
        return sqrt(real * real + imagi * imagi);
    }

    // Метод для тригонометрической формы комплексного числа
    string trigonometric_form() const {
        // Вычисление модуля
        double modulus = sqrt(real * real + imagi * imagi);

        // Вычисление аргумента, atan2 - аркатнгенс от 2 аргументов
        double theta = atan2(imagi, real);

        // Тригонометрическая форма
        return std::to_string(modulus) + " * (cos(" + std::to_string(theta) + ") + i*sin(" + std::to_string(theta) + "))";
    }


    // Метод для сравнения двух комплексных чисел
    bool is_equal(const ComplexNumber& other) const {
        return (real == other.real) && (imagi == other.imagi);
    }
};

// Функция выбора действия
int chois() {
    int choise;
    cout << " Операции над комплексными числами\n";
    cout << "1 - Сложение\n";
    cout << "2 - Вычитание\n";
    cout << "3 - Умножение\n";
    cout << "4 - Деление\n";
    cout << "5 - Сравнение\n";
    cout << "6 - Модуль\n";
    cout << "7 - Тригонометрическая формула\n";
    cout << "\n Выберите действие : \n";
    cin >> choise;
    return choise;
}

void run_tests() {
    ComplexNumber num1(3, 4);
    ComplexNumber num2(1, -1);

    // Тест сложения
    ComplexNumber result_sum = ComplexNumber::sum(num1, num2);
    assert(result_sum.is_equal(ComplexNumber(4, 3)));

    // Тест вычитания
    ComplexNumber result_sub = ComplexNumber::sub(num1, num2);
    assert(result_sub.is_equal(ComplexNumber(2, 5)));

    // Тест умножения
    ComplexNumber result_multiply = ComplexNumber::multiply(num1, num2);
    assert(result_multiply.is_equal(ComplexNumber(7, 1)));

    // Тест деления
    ComplexNumber result_divide = ComplexNumber::divide(num1, num2);
    assert(std::abs(result_divide.get_real() - (-0.5)) < 0.000001);
    assert(std::abs(result_divide.get_imagi() - 3.5) < 0.000001);

    // Тест модуля
    double mod = num1.modulus();
    assert(std::abs(mod - 5.0) < 0.000001);

    // Тест сравнения
    assert(num1.is_equal(ComplexNumber(3, 4)));
    assert(!num1.is_equal(num2));

}
