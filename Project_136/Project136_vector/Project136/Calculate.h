#pragma once
#include <cassert>

using namespace std;

/// Пространство имён с функциями для работы с векторами
namespace vector_space {
    /// Функция для получения данных от пользователя и заполнения вектора, где v - вектор
    template <typename T>
    void receive_data(vector<T> &v) {
        for (size_t i = 0; i < v.size(); i++) { // Цикл по всем элементам вектора
            cout << "Введите " << i + 1 << " элемент вектора: "; // Запрос ввода элемента
            cin >> v[i]; // Чтение элемента и сохранение в вектор
        }
    }

    /// Функция для заполнения вектора случайными числами, где v - вектор
    template <typename T>
    void rand_mas(vector<T>& v) {
        for (size_t i = 0; i < v.size(); i++) { // Цикл по всем элементам вектора
            v[i] = 1 + rand() % 100; // Генерация случайного числа от 1 до 100
        }
    }

    /// Функция подсчёта суммы модулей элементов вектора, где v - вектор
    template <typename T>
    float calculate(vector<T>& v) {
        float res = 0; // Переменная для хранения суммы
        for (size_t i = 0; i < v.size(); i++) { // Цикл по всем элементам вектора
            res += abs(v[i]); // Добавление модуля текущего элемента к сумме
        }
        return res; // Возврат итоговой суммы
    }

    ///Функция для вывода данных в консоль, где v - вектор
    template <typename T>
    void output_terminal(vector<T>& v) {
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i] << ' '; // Вывод каждого элемента вектора
        }
    }

    /// Функция для записи вектора в текстовый файл, где v - вектор, namef - имя файла
    template <typename T>
    void input_txt_file(vector<T>& v, const string& namef) {
        ofstream file(namef, ios_base::out); // Открытие файла для записи
        if (file.is_open()) { // Проверка, успешно ли открыт файл
            for (size_t i = 0; i < v.size(); i++) { // Цикл по всем элементам вектора
                file << v[i] << endl; // Запись каждого элемента в файл с переводом строки
            }
        }
    }


    /// Функция для чтения данных из  текстового файла и заполнения вектора, где v - вектор, namef - имя файла
    template <typename T>
    void output_txt_file(vector<T>& v, const string& namef) {
        ifstream file(namef); // Открытие файла для чтения
        if (file.is_open()) { // Проверка, успешно ли открыт файл
            for (size_t i = 0; i < v.size(); i++) { // Цикл по всем элементам вектора
                file >> v[i]; // Чтение значения из файла и сохранение в вектор
            }
        }
    }


    /// Функция для тестов
    void test() {
        // Тест 1: положительные числа
        float test_v1[] = { 3, 5, 6 };
        assert(calculate(test_v1, 3) == 14);

        // Тест 2: отрицательные числа
        float test_v2[] = { -3, -5, -6 };
        assert(calculate(test_v2, 3) == 14);

        // Тест 3: числа с запятой
        float test_v3[] = { 3.5f, 5.3f, 6.8f };
        assert(fabs(calculate(test_v3, 3) - 15.6f) <= 0.0000000001);
    }

    /// Функция для записи вектора в бинарный файл, где v - вектор, namef - имя файла
    template <typename T>
    void input_bin_file(vector<T>& v, const string& namef) {
        ofstream file(namef, ios::binary); // Открытие бинарного файла для записи
        if (file.is_open()) { // Проверка, успешно ли открыт файл
            file.write(reinterpret_cast<char*>(v), v.size() * sizeof(T)); // Запись вектора в файл
            file.close(); // Закрытие файла
        }
        else {
            cerr << "Не удалось открыть файл для записи." << endl; // Сообщение об ошибке
        }
    }

    /// Функция для чтения данных из бинарного файла и заполнения вектора, где v - вектор, namef - имя файла
    template <typename T>
    void output_bin_file(vector<T>& v, const string& namef) {
        ifstream file(namef, ios::binary); // Открытие бинарного файла для чтения
        if (file.is_open()) { // Проверка, успешно ли открыт файл
            file.read(reinterpret_cast<char*>(v), v.size() * sizeof(T)); // Чтение вектора из файла
            file.close(); // Закрытие файла
        }
        else {
            cerr << "Не удалось открыть файл для чтения." << endl; // Сообщение об ошибке
        }
    }

}
