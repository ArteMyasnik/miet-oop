#ifndef INVALID_VALUE_ERROR_HPP
#define INVALID_VALUE_ERROR_HPP

#include "ValidationError.hpp"

class InvalidValueError : public ValidationError {
public:
    explicit InvalidValueError(const std::string& details) 
        : ValidationError("Ошибка: Недопустимое значение (" + details + ")") {}
};

#endif