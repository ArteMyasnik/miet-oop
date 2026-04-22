#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class DynamicArray {
private:
    int n;      // размер массива
    T* Br;      // начальный адрес (указатель на массив)
    T* Tr;      // рабочий указатель

public:
    // Конструктор
    DynamicArray(int size, T minVal = -100, T maxVal = 100);
    
    // Деструктор
    ~DynamicArray();
    
    // Запрещаем копирование (для простоты)
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;
    
    // Печать массива в табличном виде
    void print(int cols = 5) const;
    
    // Поиск максимального положительного элемента (возврат указателя)
    T* findMaxPositive();
    
    // Геттеры
    int getSize() const { return n; }
    T* getData() const { return Br; }
    
    // Оператор доступа по индексу
    T& operator[](int index);
    const T& operator[](int index) const;
};

// ========== ПОДКЛЮЧАЕМ РЕАЛИЗАЦИИ ==========
#include "../src/DynamicArray.tpp"

#endif // DYNAMIC_ARRAY_HPP