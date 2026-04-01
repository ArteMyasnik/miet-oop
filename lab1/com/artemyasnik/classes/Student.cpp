#include <iostream>
#include <cstring>
#include "Student.hpp"


Student::Student(const char* f, const char* n, const int g) {
    fam = new char[strlen(f) + 1];
    strcpy(fam, f);

    name = new char[strlen(n) + 1];
    strcpy(name, n);

    grup = g;
}

Student::~Student() {
    delete[] fam;
    delete[] name;
}

const char* Student::getFam() const { return fam; }
const char* Student::getName() const { return name; }
unsigned int Student::getGrup() const { return grup; }

void Student::printEntity() {
    std::cout << getFam() << "\t\t" << getName() << "\t\t" << getGrup() << std::endl;
}