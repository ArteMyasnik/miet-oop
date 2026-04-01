#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include <string>
#include "Student.hpp"

class Database {
private:
    std::vector<Student*> students; 

public:
    Database();
    ~Database();

    void add(Student* s);
    void clear();
    
    void findByName(const char* f, const char* n) const;
    void filterByGroup(unsigned int groupNumber) const;
    
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    
    const std::vector<Student*>& getAll() const;
};

#endif