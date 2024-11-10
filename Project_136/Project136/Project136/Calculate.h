#pragma once
#include <cassert>
using namespace std;

/// Пространство имён с функциями для работы с массивами
namespace arrays {
    /// Функция для получения данных от пользователя и заполнения массива, где arr - указатель на массив, n - размер массива
    template <typename T>
    void receive_data(T* arr, size_t n) {
        for (size_t i = 0; i < n; i++) { // Цикл по всем элементам массива
            cout << "Введите " << i + 1 << " элемент массива: "; // Запрос ввода элемента
            cin >> arr[i]; // Чтение элемента и сохранение в массив
        }
    }

    /// Функция для заполнения массива случайными числами, где arr - указатель на массив, n - размер массива
    template <typename T>
    void rand_mas(T* arr, size_t n) {
        for (size_t i = 0; i < n; i++) { // Цикл по всем элементам массива
            arr[i] = 1 + rand() % 100; // Генерация случайного числа от 1 до 100
        }
    }

    /// Функция подсчёта суммы модулей элементов массива, где arr - указатель на массив, n - размер массива
    template <typename T>
    float calculate(T* arr, size_t n) {
        float res = 0; // Переменная для хранения суммы
        for (size_t i = 0; i < n; i++) { // Цикл по всем элементам массива
            res += abs(arr[i]); // Добавление модуля текущего элемента к сумме
        }
        return res; // Возврат итоговой суммы
    }

    ///Функция для вывода данных в консоль, где arr - указатель на массив, n - размер массива
    template <typename T>
    void output_terminal(T* arr, size_t n) {
        cout << "Массив: "; // Вывод массива на экран 
        for (size_t i = 0; i < n; i++) {
            cout << arr[i] << ' '; // Вывод каждого элемента массива
        }
    }


    /// Функция для записи массива в текстовый файл, где arr - указатель на массив, n - размер массива, namef - имя файла
    template <typename T>
    void input_txt_file(T* arr, const string& namef, size_t n) {
        ofstream file(namef, ios_base::out); // Открытие файла для записи
        if (file.is_open()) { // Проверка, успешно ли открыт файл
            for (size_t i = 0; i < n; i++) { // Цикл по всем элементам массива
                file << arr[i] << endl; // Запись каждого элемента в файл с переводом строки
            }
        }
        file.close();
    }


    /// Функция для чтения данных из  текстового файла и заполнения массива, где arr - указатель на массив, n - размер массива, namef - имя файла
    template <typename T>
    void output_txt_file(T* arr, const string& namef, size_t n) {
        ifstream file(namef); // Открытие файла для чтения
        if (file.is_open()) { // Проверка, успешно ли открыт файл
            for (size_t i = 0; i < n; i++) { // Цикл по всем элементам массива
                file >> arr[i]; // Чтение значения из файла и сохранение в массив
            }
        }
        file.close();
    }

    /// Возвращает кол-ва элементов массива в текстовом файле, namef - имя файла в котором хранится массив
    size_t array_size_from_file(const string& namef) {
        size_t n = 0;// Переменная для счета кол-ва строк
        string line;// Строка, с помощью которой ищем кол-во строк
        ifstream file(namef);// Открытие файла 

        if (!file.is_open()) // Если файл не открыт, то выводим ошибку
        {
            throw runtime_error("Ошибка открытия файла");              
            return 0;
        }

        while (getline(file, line))// Считаем кол-во строк = кол-ва элементов массива
        {
            n++;
        }
        if (n == 0)// Если файл пустой
        {
            throw runtime_error("Файл пустой");// Ошибка пустого файла
        }
        file.close();// Закрываем файл
        return n;
    }

   

    /// Функция для записи массива в бинарный файл, где arr - указатель на массив, n - размер массива, namef - имя файла
    template <typename T>
    void input_bin_file(T* arr, const string& namef, size_t n) {
        ofstream file(namef, ios::binary); // Открытие бинарного файла для записи
        if (file.is_open()) { // Проверка, успешно ли открыт файл
            file.write(reinterpret_cast<char*>(arr), n * sizeof(T)); // Запись массива в файл
            file.close(); // Закрытие файла
        }
        else {
            throw runtime_error("не удалось открыть файл"); // Сообщение об ошибке
        }
    }

    /// Функция для чтения данных из бинарного файла и заполнения массива, где arr - указатель на массив, n - размер массива, namef - имя файла
    template <typename T>
    void output_bin_file(T* arr, const string& namef, size_t n) {
        ifstream file(namef, ios::binary); // Открытие бинарного файла для чтения
        if (file.is_open()) { // Проверка, успешно ли открыт файл
            file.read(reinterpret_cast<char*>(arr), n * sizeof(T)); // Чтение массива из файла
            file.close(); // Закрытие файла
        }
        else {
            throw runtime_error("не удалось открыть файл"); // Сообщение об ошибке
        }
    }

    /// Функция для определения размера массива в бинарном файле, где namef - имя файла
    size_t get_array_size(const string& namef) {
        ifstream file(namef, ios::binary); // Открытие бинарного файла для чтения
        if (!file.is_open()) { // Проверка, успешно ли открыт файл
            cerr << "Не удалось открыть файл." << endl;
            return 0; // Возвращаем 0 в случае ошибки
        }
        // Перемещаем указатель в конец файла
        file.seekg(0, ios::end);
        size_t size_in_bytes = static_cast<size_t>(file.tellg()); // Получаем размер файла в байтах

        file.close(); // Закрываем файл

        size_t element_size = sizeof(float); // Размер одного элемента (float)

        if (element_size == 0) {
            throw runtime_error("Размер элемента не может быть нулевым.");
            return 0; // Защита от деления на ноль
        }

        return size_in_bytes / element_size; // Возвращаем количество элементов в массиве
    }

    /// Функция для тестов
    void test() {
        // Тест 1: положительные числа
        float test_arr1[] = { 3, 5, 6 };
        assert(calculate(test_arr1, 3) == 14);

        // Тест 2: отрицательные числа
        // Тест 2: отрицательные числа
        float test_arr2[] = { -3, -5, -6 };
        assert(calculate(test_arr2, 3) == 14);

        // Тест 3: числа с запятой
        float test_arr3[] = { 3.5f, 5.3f, 6.8f };
        assert(abs(calculate(test_arr3, 3) - 15.6f) <= 0.0000000001);
    }
}
