#include "StudentValidator.hpp"
#include "../exceptions/AllExceptions.hpp"
#include <algorithm>
#include <cstring>
#include <cctype>

bool StudentValidator::isValidFormat(const std::string& str) const {
    size_t len = str.length();
    size_t i = 0;
    
    while (i < len) {
        unsigned char ch = static_cast<unsigned char>(str[i]);
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) { 
            i++; 
            continue; 
        }
        // Русские буквы в UTF-8 (2 байта)
        if (ch == 0xD0 || ch == 0xD1) {
            if (i + 1 < len) {
                unsigned char ch2 = static_cast<unsigned char>(str[i + 1]);
                if (ch2 >= 0x80 && ch2 <= 0xBF) { 
                    i += 2; 
                    continue; 
                }
            }
            return false;
        }
        return false;
    }
    return true;
}

bool StudentValidator::isValidDate() const {
    if (day == 0 && month == 0 && year == 0) return true;
    
    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 1900 || year > 2026) return false;
    
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];
    
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear) maxDay = 29;
    }
    
    return day <= maxDay;
}

void StudentValidator::validate() const {
    if (fam.empty()) throw EmptyFieldError("Фамилия");
    if (!isValidFormat(fam)) throw InvalidFormatError("Фамилия (допустимы только буквы)");
    
    if (name.empty()) throw EmptyFieldError("Имя");
    if (!isValidFormat(name)) throw InvalidFormatError("Имя (допустимы только буквы)");
    
    if (grup <= 0) throw InvalidValueError("Группа (должна быть положительным числом)");
    if (!isValidDate()) throw InvalidValueError("Дата рождения (некорректные значения)");
}