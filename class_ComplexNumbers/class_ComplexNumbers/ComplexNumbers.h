#pragma once
#include <string>
#include <math.h>

using namespace std;
/// ����� - ����������� ���� ����������� �����, ��� ���� real - �������������� ����� �����, imagi - ������
class ComplexNumber {

private:
    double real;
    double imagi;

public:
    // ����������� �� ���������
    ComplexNumber() {
        real = 0;
        imagi = 0;
    }

    // ����������� � �����������
    ComplexNumber(double r, double im) {
        set_real(r);
        set_imagi(im);
    }

    /// ��������� �������� �������������� ����� ������������ ����� 
    void set_real(double r) { real = r; }

    /// ��������� �������� ������ ����� ������������ ����� 
    void set_imagi(double im) { imagi = im; }

    /// ��������� �������� �������������� ����� ������������ �����
    double get_real() const { return real; }

    /// ��������� �������� ������ ����� ������������ �����
    double get_imagi() const { return imagi; }

    /// ����� ��� ��������� ���������� �������������
    string to_string() const {
        return std::to_string(real) + " + " + std::to_string(imagi) + "i";
    }

    /// ����� ��� ����� 2 ����������� �����, ��� num1, num2 - ����������� �����
    static ComplexNumber sum(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real + num2.real, num1.imagi + num2.imagi);
    }

    /// ����� ��� ��������� 2 ����������� �����, ��� num1, num2 - ����������� �����
    static ComplexNumber sub(const ComplexNumber& num1, const ComplexNumber& num2) {
        return ComplexNumber(num1.real - num2.real, num1.imagi - num2.imagi);
    }

    /// ����� ��� ��������� 2 ����������� �����, ��� num1, num2 - ����������� �����
    static ComplexNumber multiply(const ComplexNumber& num1, const ComplexNumber& num2) {
        double r = (num1.real * num2.real) - (num1.imagi * num2.imagi);
        double im = (num1.real * num2.imagi) + (num1.imagi * num2.real);
        return ComplexNumber(r, im);
    }

    /// ����� ��� ������� ���� ����������� �����, ��� num1, num2 - ����������� �����
    static ComplexNumber divide(const ComplexNumber& num1, const ComplexNumber& num2) {
        if (num2.real == 0 && num2.imagi == 0) {
            throw std::invalid_argument("������� �� ����!");// ������ ������� �� ����
        }

        // ���������� � ������� �����
        ComplexNumber conjugate(num2.real, -num2.imagi);

        // �������� ��������� � ����������� �� ����������
        ComplexNumber numerator = multiply(num1, conjugate);
        double denominator = multiply(num2, conjugate).real; // �������������� ����� �����������

        return ComplexNumber(numerator.real / denominator, numerator.imagi / denominator);
    }

};

int chois() {
    int choise;
    cout << " �������� ��� ������������ �������\n";
    cout << "1 - ��������\n";
    cout << "2 - ���������\n";
    cout << "3 - ���������\n";
    cout << "4 - �������\n";
    cout << "\n �������� �������� : \n";
    cin >> choise;
    return choise;
}