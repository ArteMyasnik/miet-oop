#include "StudentValidator.hpp"
#include "../exceptions/AllExceptions.hpp"
#include <cstring>
#include <cctype>

bool StudentValidator::isValidFormat(const char* str) const {
    for (size_t i = 0; i < std::strlen(str); ++i) {
        if (!std::isalpha(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

void StudentValidator::validate() const {
    if (std::strlen(fam) == 0) { throw EmptyFieldError("Фамилия"); }
    if (std::strlen(name) == 0) { throw EmptyFieldError("Имя"); }

    if (!isValidFormat(fam)) { throw InvalidFormatError("Фамилия"); }
    if (!isValidFormat(name)) { throw InvalidFormatError("Имя"); }

    if (grup <= 0) { throw InvalidValueError("Группа"); }

}
