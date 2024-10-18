#include <iostream>
#include <fstream>
#include "Calculate.h"

using namespace std;

void receive_data(float* arr, int& n) { // Передаем n по ссылке
    cout << "Введите кол-во элементов массива (макс. 128): ";
    cin >> n;
    if (n > 128) {
        cout << "Ошибка: максимальное количество элементов - 128." << endl;
        n = 128; // Устанавливаем n в максимальное значение
    }

    for (int i = 0; i < n; i++) {
        cout << "Введите " << i + 1 << " элемент массива: ";
        cin >> arr[i];
    }
}

float calculate(float* arr, int n) {
    float res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(arr[i]);
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "RU"); // Подключаем русский язык
    ofstream fout("test.txt"); // создаём объект класса ofstream и связываем его с файлом cppstudio.txt
    int n = 128;
    float* arr = new float[n];
    receive_data(arr, n);
    cout << "Сумма элементов массива по модулю: " << calculate(arr, n);
    delete[] arr; // Освобождаем память
    return 0;
}
