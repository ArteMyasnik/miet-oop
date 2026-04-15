#ifndef STUDENT_VALIDATOR_HPP
#define STUDENT_VALIDATOR_HPP

#include "IValidator.hpp"

class StudentValidator : public IValidator {
private:
    const char* fam;
    const char* name;
    int grup;
    int day;
    int month;
    int year;

    bool isValidFormat(const char* str) const;
    bool isValidDate() const;

public:
    StudentValidator(const char* f, const char* n, int g) 
        : fam(f), name(n), grup(g), day(0), month(0), year(0) {}
        
    StudentValidator(const char* f, const char* n, int g, int d, int m, int y) 
        : fam(f), name(n), grup(g), day(d), month(m), year(y) {}

    void validate() const override;
};

#endif