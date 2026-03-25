#ifndef STUDENT_H
#define STUDENT_H

#include "../interfaces/IPrintable.hpp"
#include <cstring>

class Student : public IPrintable {
    private:
        char* fam;
        char* name;
        int grup;
    public:
        Student(const char* f, const char* n, const int g);
        virtual ~Student();
        
        void printEntity() override;
        
        const char* getFam() const;
        const char* getName() const;
        int getGrup() const;
};

#endif