#ifndef ARRAY_FUNCTIONS_HPP
#define ARRAY_FUNCTIONS_HPP

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>

// ========== ОБЪЯВЛЕНИЯ ШАБЛОННЫХ ФУНКЦИЙ ==========

// 1. Инициализация массива случайными числами (обобщённая)
template<typename T>
void initRandom(T* arr, int size, T minVal = -100, T maxVal = 100);

// 2. Создание массива индексов элементов, не превосходящих K
template<typename T>
std::vector<int> getIndicesWhereNotExceed(T* arr, int size, T K);

// 3. Вспомогательная функция: вывод массива
template<typename T>
void printArray(const T* arr, int size, const std::string& name = "Массив");

// 4. Вспомогательная функция: вывод индексов
void printIndices(const std::vector<int>& indices, const std::string& name = "Индексы");

// ========== ЯВНАЯ ПЕРЕГРУЗКА ДЛЯ CHAR (НЕ ШАБЛОН) ==========
void initRandom(char* arr, int size, char minVal = 'A', char maxVal = 'Z');

// ========== ПОДКЛЮЧАЕМ РЕАЛИЗАЦИИ ==========
#include "../src/array_functions.tpp"

#endif // ARRAY_FUNCTIONS_HPP