#ifndef IPRINTABLE_H
#define IPRINTABLE_H

class IPrintable {
public:
    virtual void printEntity() = 0;
    virtual ~IPrintable() {}
};

#endif