#ifndef IVALIDATOR_HPP
#define IVALIDATOR_HPP

class IValidator {
public:
    virtual ~IValidator() {}
    virtual void validate() const = 0;
};

#endif