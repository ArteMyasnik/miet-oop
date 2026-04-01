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

void StudentValidator::validate() const {
    if (std::strlen(fam) == 0) { throw EmptyFieldError("Фамилия"); }
    if (std::strlen(name) == 0) { throw EmptyFieldError("Имя"); }

    if (!isValidFormat(fam)) { throw InvalidFormatError("Фамилия (допустимы только буквы)"); }
    if (!isValidFormat(name)) { throw InvalidFormatError("Имя (допустимы только буквы)"); }

    if (grup <= 0) { throw InvalidValueError("Группа"); }
}