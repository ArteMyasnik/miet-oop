#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
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
                std::cout << "\nФамилия\t\tИмя\t\tГруппа" << std::endl;
                std::cout << "----------------------------------------" << std::endl;
            }
            s->printEntity();
            found = true;
        }
    }
    if (!found) std::cout << "Студент не найден" << std::endl;
}

void Database::filterByGroup(unsigned int groupNumber) const {
    bool found = false;
    
    for (auto s : students) {
        if (s->getGrup() == groupNumber) {
            if (!found) {
                std::cout << "\nФамилия\t\tИмя\t\tГруппа" << std::endl;
                std::cout << "----------------------------------------" << std::endl;
            }
            s->printEntity();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "Записей для группы " << groupNumber << " не найдено." << std::endl;
    }
}

void Database::saveToFile(const std::string& filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл для записи!" << std::endl;
        return;
    }
    out << "Surname;Name;Group\n";
    for (auto s : students) {
        out << s->getFam() << ";" 
            << s->getName() << ";" 
            << s->getGrup() << "\n";
    }
    out.close();
}

void Database::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) return;

    std::string line;
    clear();
    std::getline(in, line); 

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string f, n, g_str;

        if (std::getline(ss, f, ';') && 
            std::getline(ss, n, ';') && 
            std::getline(ss, g_str)) {
            
            try {
                int g = std::stoi(g_str);
                add(new Student(f.c_str(), n.c_str(), g));
            } catch (...) {
                continue;
            }
        }
    }
    in.close();
}

const std::vector<Student*>& Database::getAll() const { return students; }