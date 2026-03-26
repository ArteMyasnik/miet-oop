#ifndef EMPTY_FIELD_ERROR_HPP
#define EMPTY_FIELD_ERROR_HPP

#include "ValidationError.hpp"

class EmptyFieldError : public ValidationError {
public:
    explicit EmptyFieldError(const std::string& fieldName) 
        : ValidationError("Ошибка: Поле '" + fieldName + "' не может быть пустым!") {}
};

#endif