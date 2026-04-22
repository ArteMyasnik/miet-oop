#include <iostream>
#include <vector>
#include "include/array_functions.hpp"
#include "include/DynamicArray.hpp"

int main() {
    std::cout << "========== ЛАБОРАТОРНАЯ РАБОТА №5 (Вариант 4) ==========\n\n";
    
    std::cout << "========== ЧАСТЬ 1: Шаблонные функции ==========\n\n";
    
    const int SIZE = 10;
    
    // Тест с int
    std::cout << "--- Тип int ---\n";
    int* intArr = new int[SIZE];
    initRandom(intArr, SIZE, -50, 50);
    printArray(intArr, SIZE, "int массив");
    
    int K_int = 10;
    std::cout << "K = " << K_int << std::endl;
    std::vector<int> indices_int = getIndicesWhereNotExceed(intArr, SIZE, K_int);
    printIndices(indices_int, "Индексы элементов <= K");
    std::cout << std::endl;
    
    // Тест с double
    std::cout << "--- Тип double ---\n";
    double* doubleArr = new double[SIZE];
    initRandom(doubleArr, SIZE, -50.0, 50.0);
    printArray(doubleArr, SIZE, "double массив");
    
    double K_double = 10.0;
    std::cout << "K = " << K_double << std::endl;
    std::vector<int> indices_double = getIndicesWhereNotExceed(doubleArr, SIZE, K_double);
    printIndices(indices_double, "Индексы элементов <= K");
    std::cout << std::endl;
    
    // Тест с char (явная перегрузка)
    std::cout << "--- Тип char (явная перегрузка) ---\n";
    char* charArr = new char[SIZE];
    initRandom(charArr, SIZE, 'A', 'Z');
    printArray(charArr, SIZE, "char массив");
    
    char K_char = 'M';
    std::cout << "K = " << K_char << std::endl;
    std::vector<int> indices_char = getIndicesWhereNotExceed(charArr, SIZE, K_char);
    printIndices(indices_char, "Индексы элементов <= K");
    std::cout << std::endl;
    
    delete[] intArr;
    delete[] doubleArr;
    delete[] charArr;
    
    std::cout << "\n========== ЧАСТЬ 2: Шаблонный класс DynamicArray ==========\n\n";
    
    // DynamicArray<int>
    std::cout << "--- DynamicArray<int> ---\n";
    DynamicArray<int> intArray(12, -100, 100);
    intArray.print(6);
    
    int* maxPosInt = intArray.findMaxPositive();
    if (maxPosInt != nullptr) {
        std::cout << "Максимальный положительный элемент: " << *maxPosInt 
                  << " (адрес: " << maxPosInt << ")" << std::endl;
    } else {
        std::cout << "Положительных элементов нет" << std::endl;
    }
    std::cout << std::endl;
    
    // DynamicArray<double>
    std::cout << "--- DynamicArray<double> ---\n";
    DynamicArray<double> doubleArray(10, -99.9, 99.9);
    doubleArray.print(5);
    
    double* maxPosDouble = doubleArray.findMaxPositive();
    if (maxPosDouble != nullptr) {
        std::cout << "Максимальный положительный элемент: " << *maxPosDouble 
                  << " (адрес: " << maxPosDouble << ")" << std::endl;
    } else {
        std::cout << "Положительных элементов нет" << std::endl;
    }    
    return 0;
}