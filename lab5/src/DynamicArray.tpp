#ifndef DYNAMIC_ARRAY_TPP
#define DYNAMIC_ARRAY_TPP

#include "../include/DynamicArray.hpp"
#include <random>
#include <ctime>
#include <iomanip>
#include <type_traits>

// ========== КОНСТРУКТОР ==========
template<typename T>
DynamicArray<T>::DynamicArray(int size, T minVal, T maxVal) : n(size) {
    Br = new T[n];
    Tr = Br;
    
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    
    if constexpr (std::is_integral<T>::value) {
        std::uniform_int_distribution<T> dist(minVal, maxVal);
        for (int i = 0; i < n; i++) {
            Br[i] = dist(rng);
        }
    } else if constexpr (std::is_floating_point<T>::value) {
        std::uniform_real_distribution<T> dist(minVal, maxVal);
        for (int i = 0; i < n; i++) {
            Br[i] = dist(rng);
        }
    }
}

// ========== ДЕСТРУКТОР ==========
template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] Br;
    Br = nullptr;
    Tr = nullptr;
}

// ========== ПЕЧАТЬ МАССИВА ==========
template<typename T>
void DynamicArray<T>::print(int cols) const {
    std::cout << "Массив (" << typeid(T).name() << ", размер=" << n << "):" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(10) << Br[i] << " ";
        if ((i + 1) % cols == 0 || i == n - 1) {
            std::cout << std::endl;
        }
    }
    std::cout << "----------------------------------------" << std::endl;
}

// ========== ПОИСК МАКСИМАЛЬНОГО ПОЛОЖИТЕЛЬНОГО ЭЛЕМЕНТА ==========
template<typename T>
T* DynamicArray<T>::findMaxPositive() {
    T* maxPtr = nullptr;
    
    for (int i = 0; i < n; i++) {
        if (Br[i] > 0) {
            if (maxPtr == nullptr || Br[i] > *maxPtr) {
                maxPtr = &Br[i];
            }
        }
    }
    
    return maxPtr;
}

// ========== ОПЕРАТОРЫ ДОСТУПА ==========
template<typename T>
T& DynamicArray<T>::operator[](int index) {
    return Br[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](int index) const {
    return Br[index];
}

#endif // DYNAMIC_ARRAY_TPP