#ifndef STUDENT_VALIDATOR_HPP
#define STUDENT_VALIDATOR_HPP

#include "IValidator.hpp"

class StudentValidator : public IValidator {
private:
    const char* fam;
    const char* name;
    int grup;

    bool isValidFormat(const char* str) const;

public:
    StudentValidator(const char* f, const char* n, int g) 
        : fam(f), name(n), grup(g) {}

    void validate() const override;
};

#endif