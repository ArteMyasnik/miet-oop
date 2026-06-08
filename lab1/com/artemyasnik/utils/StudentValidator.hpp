#ifndef STUDENT_VALIDATOR_HPP
#define STUDENT_VALIDATOR_HPP

#include "IValidator.hpp"
#include <string>
#include <algorithm>
#include <functional>

class StudentValidator : public IValidator {
private:
    std::string fam;
    std::string name;
    int grup;
    int day;
    int month;
    int year;

    bool isValidFormat(const std::string& str) const;
    bool isValidDate() const;

public:
    StudentValidator(const char* f, const char* n, int g) 
        : fam(f ? f : ""), name(n ? n : ""), grup(g), day(0), month(0), year(0) {}
        
    StudentValidator(const char* f, const char* n, int g, int d, int m, int y) 
        : fam(f ? f : ""), name(n ? n : ""), grup(g), day(d), month(m), year(y) {}

    void validate() const override;
};

#endif