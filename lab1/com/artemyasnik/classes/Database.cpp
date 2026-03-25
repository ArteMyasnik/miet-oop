#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Database.hpp"


Database::Database() {}

Database::~Database() { clear(); }

void Database::add(Student* s) { students.push_back(s); }

void Database::clear() {
    for (auto s : students) {
        delete s;
    }
    students.clear();
}

void Database::findByName(const char* f, const char* n) const {
    bool found = false;
    for (auto s : students) {
        if (std::strcmp(s->getFam(), f) == 0 && std::strcmp(s->getName(), n) == 0) {
            if (!found) {
                std::cout << std::left << std::setw(20) << "Фамилия" 
                          << std::setw(20) << "Имя" << "Группа" << std::endl;
                std::cout << "---------------------------------------" << std::endl;
            }
            s->printEntity();
            found = true;
        }
    }
    if (!found) std::cout << "Student is not found" << std::endl;
}

void Database::filterByGroup(int groupNumber) const {
    bool found = false;
    
    for (auto s : students) {
        if (s->getGrup() == groupNumber) {
            if (!found) {
                std::cout << std::left << std::setw(20) << "Фамилия" 
                          << std::setw(20) << "Имя" 
                          << "Группа" << std::endl;
                std::cout << "---------------------------------------" << std::endl;
            }
            s->printEntity();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "Записей для группы " << groupNumber << " не найдено." << std::endl;
    }
}

const std::vector<Student*>& Database::getAll() const { return students; }