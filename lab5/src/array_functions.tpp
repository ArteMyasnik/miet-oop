#ifndef ARRAY_FUNCTIONS_TPP
#define ARRAY_FUNCTIONS_TPP

#include "../include/array_functions.hpp"
#include <type_traits>

// ========== РЕАЛИЗАЦИЯ ШАБЛОННЫХ ФУНКЦИЙ ==========

// 1. Инициализация случайными числами
template<typename T>
void initRandom(T* arr, int size, T minVal, T maxVal) {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    
    if constexpr (std::is_integral<T>::value) {
        std::uniform_int_distribution<T> dist(minVal, maxVal);
        for (int i = 0; i < size; i++) {
            arr[i] = dist(rng);
        }
    } else if constexpr (std::is_floating_point<T>::value) {
        std::uniform_real_distribution<T> dist(minVal, maxVal);
        for (int i = 0; i < size; i++) {
            arr[i] = dist(rng);
        }
    }
}

// 2. Получение индексов элементов, не превосходящих K
template<typename T>
std::vector<int> getIndicesWhereNotExceed(T* arr, int size, T K) {
    std::vector<int> indices;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= K) {
            indices.push_back(i);
        }
    }
    return indices;
}

// 3. Вывод массива
template<typename T>
void printArray(const T* arr, int size, const std::string& name) {
    std::cout << name << ": ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif // ARRAY_FUNCTIONS_TPP