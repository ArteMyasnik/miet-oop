#ifndef IVALIDATOR_H
#define IVALIDATOR_H

class IValidator {
public:
    virtual ~IValidator() {}
    virtual void validate() const = 0;
};

#endif