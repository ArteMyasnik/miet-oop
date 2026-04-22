#include "../include/array_functions.hpp"
#include <random>
#include <ctime>
#include <iostream>

// Реализация явно перегруженной функции для char
void initRandom(char* arr, int size, char minVal, char maxVal) {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(static_cast<int>(minVal), static_cast<int>(maxVal));
    
    for (int i = 0; i < size; i++) {
        arr[i] = static_cast<char>(dist(rng));
    }
    std::cout << "  [char] Явная перегрузка: инициализация буквами латинского алфавита" << std::endl;
}

// Реализация printIndices (нешаблонная)
void printIndices(const std::vector<int>& indices, const std::string& name) {
    std::cout << name << ": ";
    if (indices.empty()) {
        std::cout << "(нет элементов)";
    } else {
        for (size_t i = 0; i < indices.size(); i++) {
            std::cout << indices[i] << " ";
        }
    }
    std::cout << std::endl;
}