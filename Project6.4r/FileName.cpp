#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

// ������� ��� ��������� �� ���������� ���������� ������ ����������� �������
void createDynamicArray(vector<double>& array, int size) {
    array.resize(size);
    for (int i = 0; i < size; i++) {
        array[i] = static_cast<double>(rand() % 100 - 50);  // ���������� �������� ����� �� -50 �� 49
    }
}

// ������� ��� ��������� ������ �� ����� � ������ �����
void printDynamicArray(const vector<double>& array) {
    for (double num : array) {
        cout << num << ' ';
    }
    cout << endl;
}

// ������� ��� ���������� ������� ��'����� �������� ������ ����������� ��������
double calculateNegativeProductRecursive(const vector<double>& array, int index) {
    if (index < 0) {
        return 1.0;  // ������� �������: ���� ��������� ������� ������, ��������� 1
    }

    if (array[index] < 0) {
        return array[index] * calculateNegativeProductRecursive(array, index - 1);
    }

    return calculateNegativeProductRecursive(array, index - 1);
}

// ������� ��� ���������� ���� ��� �������� �������� ������ ����������� ��������
double calculateSumOfAllPositivesRecursive(const vector<double>& array, int index) {
    if (index < 0) {
        return 0.0;  // ������� �������: ���� ��������� ������� ������, ��������� 0
    }

    if (array[index] > 0) {
        return array[index] + calculateSumOfAllPositivesRecursive(array, index - 1);
    }

    return calculateSumOfAllPositivesRecursive(array, index - 1);
}

// ������� ��� ���� ������� ��������� ������ �������� � ����� �� ��������� ����������� ��������
void reverseOrderOfEvenElementsRecursive(vector<double>& array, int left, int right) {
    if (left >= right) {
        return;  // ������� �������: ���� ������� �����������, ��������� �������
    }

    if (array[left] - static_cast<int>(array[left]) == 0 && array[right] - static_cast<int>(array[right]) == 0) {
        swap(array[left], array[right]);
    }

    reverseOrderOfEvenElementsRecursive(array, left + 1, right - 1);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "������ ������� �������� ������: ";
    cin >> n;

    vector<double> dynamicArray;
    createDynamicArray(dynamicArray, n);

    cout << "������������ �����: ";
    printDynamicArray(dynamicArray);

    // �������� 1.1: ������� ��'����� �������� ������ (����������� �����)
    double negativeProduct = calculateNegativeProductRecursive(dynamicArray, dynamicArray.size() - 1);
    cout << "������� ��'����� �������� (����������� �����): " << negativeProduct << endl;

    // �������� 1.2: ���������� ���� ��� �������� �������� (����������� �����)
    double sumOfAllPositives = calculateSumOfAllPositivesRecursive(dynamicArray, dynamicArray.size() - 1);
    cout << "���� ��� �������� �������� (����������� �����): " << sumOfAllPositives << endl;

    // �������� 2: ���� ������� ��������� ������ �������� �� ��������� (����������� �����)
    reverseOrderOfEvenElementsRecursive(dynamicArray, 0, dynamicArray.size() - 1);
    cout << "������������� ����� (������� ������� ������ ��������, ����������� �����): ";
    printDynamicArray(dynamicArray);

    return 0;
}
