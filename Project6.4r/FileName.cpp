#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

// Функція для створення та заповнення динамічного масиву випадковими числами
void createDynamicArray(vector<double>& array, int size) {
    array.resize(size);
    for (int i = 0; i < size; i++) {
        array[i] = static_cast<double>(rand() % 100 - 50);  // Генерувати випадкові числа від -50 до 49
    }
}

// Функція для виведення масиву на екран у вигляді рядка
void printDynamicArray(const vector<double>& array) {
    for (double num : array) {
        cout << num << ' ';
    }
    cout << endl;
}

// Функція для обчислення добутку від'ємних елементів масиву рекурсивним способом
double calculateNegativeProductRecursive(const vector<double>& array, int index) {
    if (index < 0) {
        return 1.0;  // Базовий випадок: якщо досягнуто початок масиву, повертаємо 1
    }

    if (array[index] < 0) {
        return array[index] * calculateNegativeProductRecursive(array, index - 1);
    }

    return calculateNegativeProductRecursive(array, index - 1);
}

// Функція для обчислення суми всіх додатних елементів масиву рекурсивним способом
double calculateSumOfAllPositivesRecursive(const vector<double>& array, int index) {
    if (index < 0) {
        return 0.0;  // Базовий випадок: якщо досягнуто початок масиву, повертаємо 0
    }

    if (array[index] > 0) {
        return array[index] + calculateSumOfAllPositivesRecursive(array, index - 1);
    }

    return calculateSumOfAllPositivesRecursive(array, index - 1);
}

// Функція для зміни порядку розміщення парних елементів в масиві на зворотний рекурсивним способом
void reverseOrderOfEvenElementsRecursive(vector<double>& array, int left, int right) {
    if (left >= right) {
        return;  // Базовий випадок: якщо індекси перетнулися, завершуємо рекурсію
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
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    vector<double> dynamicArray;
    createDynamicArray(dynamicArray, n);

    cout << "Згенерований масив: ";
    printDynamicArray(dynamicArray);

    // Завдання 1.1: Добуток від'ємних елементів масиву (рекурсивний спосіб)
    double negativeProduct = calculateNegativeProductRecursive(dynamicArray, dynamicArray.size() - 1);
    cout << "Добуток від'ємних елементів (рекурсивний спосіб): " << negativeProduct << endl;

    // Завдання 1.2: Обчислення суми всіх додатних елементів (рекурсивний спосіб)
    double sumOfAllPositives = calculateSumOfAllPositivesRecursive(dynamicArray, dynamicArray.size() - 1);
    cout << "Сума всіх додатних елементів (рекурсивний спосіб): " << sumOfAllPositives << endl;

    // Завдання 2: Зміна порядку розміщення парних елементів на зворотний (рекурсивний спосіб)
    reverseOrderOfEvenElementsRecursive(dynamicArray, 0, dynamicArray.size() - 1);
    cout << "Модифікований масив (змінений порядок парних елементів, рекурсивний спосіб): ";
    printDynamicArray(dynamicArray);

    return 0;
}
