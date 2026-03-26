#ifndef INVALID_FORMAT_ERROR_HPP
#define INVALID_FORMAT_ERROR_HPP

#include "ValidationError.hpp"

class InvalidFormatError : public ValidationError {
public:
    explicit InvalidFormatError(const std::string& field) 
        : ValidationError("Ошибка: " + field + " недопустимый формат данных!") {}
};

#endif