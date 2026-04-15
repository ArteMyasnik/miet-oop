#include "StudentValidator.hpp"
#include "../exceptions/AllExceptions.hpp"
#include <cstring>
#include <cctype>

bool StudentValidator::isValidFormat(const char* str) const {
    size_t len = std::strlen(str);
    size_t i = 0;
    
    while (i < len) {
        unsigned char ch = static_cast<unsigned char>(str[i]);
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) { i++; continue; }
        // Русские буквы в UTF-8 (2 байта)
        if (ch == 0xD0 || ch == 0xD1) {
            if (i + 1 < len) {
                unsigned char ch2 = static_cast<unsigned char>(str[i + 1]);
                if (ch2 >= 0x80 && ch2 <= 0xBF) { i += 2; continue; }
            }
            return false;
        }
        return false;
    }
    return true;
}

bool StudentValidator::isValidDate() const {
    if (day == 0 && month == 0 && year == 0) { return true; }
    if (day < 1 || day > 31) { return false; }
    if (month < 1 || month > 12) { return false; }
    if (year < 1900 || year > 2026) { return false; }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) { return false; }
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && day > 29) { return false; }
        if (!isLeapYear && day > 28) { return false; }
    }    
    return true;
}

void StudentValidator::validate() const {
    if (std::strlen(fam) == 0) { throw EmptyFieldError("Фамилия"); }
    if (!isValidFormat(fam)) { throw InvalidFormatError("Фамилия (допустимы только буквы)"); }
    if (std::strlen(name) == 0) { throw EmptyFieldError("Имя"); }
    if (!isValidFormat(name)) { throw InvalidFormatError("Имя (допустимы только буквы)"); }
    if (grup <= 0) { throw InvalidValueError("Группа (должна быть положительным числом)"); }
    if (!isValidDate()) { throw InvalidValueError("Дата рождения (некорректные значения)"); }
}