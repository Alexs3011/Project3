#pragma once
#include <cassert>
using namespace std;

/// ������������ ��� � ��������� ��� ������ � ���������
namespace arrays {
    /// ������� ��� ��������� ������ �� ������������ � ���������� �������, ��� arr - ��������� �� ������, n - ������ �������
    template <typename T>
    void receive_data(T* arr, size_t n) {
        for (size_t i = 0; i < n; i++) { // ���� �� ���� ��������� �������
            cout << "������� " << i + 1 << " ������� �������: "; // ������ ����� ��������
            cin >> arr[i]; // ������ �������� � ���������� � ������
        }
    }

    /// ������� ��� ���������� ������� ���������� �������, ��� arr - ��������� �� ������, n - ������ �������
    template <typename T>
    void rand_mas(T* arr, size_t n) {
        for (size_t i = 0; i < n; i++) { // ���� �� ���� ��������� �������
            arr[i] = 1 + rand() % 100; // ��������� ���������� ����� �� 1 �� 100
        }
    }

    /// ������� �������� ����� ������� ��������� �������, ��� arr - ��������� �� ������, n - ������ �������
    template <typename T>
    float calculate(T* arr, size_t n) {
        float res = 0; // ���������� ��� �������� �����
        for (size_t i = 0; i < n; i++) { // ���� �� ���� ��������� �������
            res += abs(arr[i]); // ���������� ������ �������� �������� � �����
        }
        return res; // ������� �������� �����
    }

    ///������� ��� ������ ������ � �������, ��� arr - ��������� �� ������, n - ������ �������
    template <typename T>
    void output_terminal(T* arr, size_t n) {
        cout << "������: "; // ����� ������� �� ����� 
        for (size_t i = 0; i < n; i++) {
            cout << arr[i] << ' '; // ����� ������� �������� �������
        }
    }


    /// ������� ��� ������ ������� � ��������� ����, ��� arr - ��������� �� ������, n - ������ �������, namef - ��� �����
    template <typename T>
    void input_txt_file(T* arr, const string& namef, size_t n) {
        ofstream file(namef, ios_base::out); // �������� ����� ��� ������
        if (file.is_open()) { // ��������, ������� �� ������ ����
            for (size_t i = 0; i < n; i++) { // ���� �� ���� ��������� �������
                file << arr[i] << endl; // ������ ������� �������� � ���� � ��������� ������
            }
        }
        file.close();
    }


    /// ������� ��� ������ ������ ��  ���������� ����� � ���������� �������, ��� arr - ��������� �� ������, n - ������ �������, namef - ��� �����
    template <typename T>
    void output_txt_file(T* arr, const string& namef, size_t n) {
        ifstream file(namef); // �������� ����� ��� ������
        if (file.is_open()) { // ��������, ������� �� ������ ����
            for (size_t i = 0; i < n; i++) { // ���� �� ���� ��������� �������
                file >> arr[i]; // ������ �������� �� ����� � ���������� � ������
            }
        }
        file.close();
    }

    /// ���������� ���-�� ��������� ������� � ��������� �����, namef - ��� ����� � ������� �������� ������
    size_t array_size_from_file(const string& namef) {
        size_t n = 0;// ���������� ��� ����� ���-�� �����
        string line;// ������, � ������� ������� ���� ���-�� �����
        ifstream file(namef);// �������� ����� 

        if (!file.is_open()) // ���� ���� �� ������, �� ������� ������
        {
            throw runtime_error("������ �������� �����");              
            return 0;
        }

        while (getline(file, line))// ������� ���-�� ����� = ���-�� ��������� �������
        {
            n++;
        }
        if (n == 0)// ���� ���� ������
        {
            throw runtime_error("���� ������");// ������ ������� �����
        }
        file.close();// ��������� ����
        return n;
    }

   

    /// ������� ��� ������ ������� � �������� ����, ��� arr - ��������� �� ������, n - ������ �������, namef - ��� �����
    template <typename T>
    void input_bin_file(T* arr, const string& namef, size_t n) {
        ofstream file(namef, ios::binary); // �������� ��������� ����� ��� ������
        if (file.is_open()) { // ��������, ������� �� ������ ����
            file.write(reinterpret_cast<char*>(arr), n * sizeof(T)); // ������ ������� � ����
            file.close(); // �������� �����
        }
        else {
            throw runtime_error("�� ������� ������� ����"); // ��������� �� ������
        }
    }

    /// ������� ��� ������ ������ �� ��������� ����� � ���������� �������, ��� arr - ��������� �� ������, n - ������ �������, namef - ��� �����
    template <typename T>
    void output_bin_file(T* arr, const string& namef, size_t n) {
        ifstream file(namef, ios::binary); // �������� ��������� ����� ��� ������
        if (file.is_open()) { // ��������, ������� �� ������ ����
            file.read(reinterpret_cast<char*>(arr), n * sizeof(T)); // ������ ������� �� �����
            file.close(); // �������� �����
        }
        else {
            throw runtime_error("�� ������� ������� ����"); // ��������� �� ������
        }
    }

    /// ������� ��� ����������� ������� ������� � �������� �����, ��� namef - ��� �����
    size_t get_array_size(const string& namef) {
        ifstream file(namef, ios::binary); // �������� ��������� ����� ��� ������
        if (!file.is_open()) { // ��������, ������� �� ������ ����
            cerr << "�� ������� ������� ����." << endl;
            return 0; // ���������� 0 � ������ ������
        }
        // ���������� ��������� � ����� �����
        file.seekg(0, ios::end);
        size_t size_in_bytes = static_cast<size_t>(file.tellg()); // �������� ������ ����� � ������

        file.close(); // ��������� ����

        size_t element_size = sizeof(float); // ������ ������ �������� (float)

        if (element_size == 0) {
            throw runtime_error("������ �������� �� ����� ���� �������.");
            return 0; // ������ �� ������� �� ����
        }

        return size_in_bytes / element_size; // ���������� ���������� ��������� � �������
    }

    /// ������� ��� ������
    void test() {
        // ���� 1: ������������� �����
        float test_arr1[] = { 3, 5, 6 };
        assert(calculate(test_arr1, 3) == 14);

        // ���� 2: ������������� �����
        // ���� 2: ������������� �����
        float test_arr2[] = { -3, -5, -6 };
        assert(calculate(test_arr2, 3) == 14);

        // ���� 3: ����� � �������
        float test_arr3[] = { 3.5f, 5.3f, 6.8f };
        assert(abs(calculate(test_arr3, 3) - 15.6f) <= 0.0000000001);
    }
}
