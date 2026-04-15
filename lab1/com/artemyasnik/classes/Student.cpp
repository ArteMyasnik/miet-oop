#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "Student.hpp"

int Student::count = 0;

// ==================== Date ====================
Student::Date::Date() : day(1), month(1), year(2000) {}

Student::Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}
Student::Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}
Student::Date::~Date() {}

int Student::Date::getDay() const { return day; }
int Student::Date::getMonth() const { return month; }
int Student::Date::getYear() const { return year; }

void Student::Date::setDay(int d) { day = d; }
void Student::Date::setMonth(int m) { month = m; }
void Student::Date::setYear(int y) { year = y; }

std::string Student::Date::toString() const {
    std::stringstream ss;
    ss << day << "." << month << "." << year;
    return ss.str();
}

void Student::Date::printEntity() const {
    std::cout << day << "." << month << "." << year;
}

void Student::Date::printEntity() {
    std::cout << day << "." << month << "." << year;
}

bool Student::Date::operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}

std::ostream& operator<<(std::ostream& os, const Student::Date& d) {
    os << d.getDay() << "." << d.getMonth() << "." << d.getYear();
    return os;
}

// ==================== Student ====================
Student::Student() : grup(0), birthday(1, 1, 2000) {
    fam = new char[1];
    name = new char[1];
    fam[0] = '\0';
    name[0] = '\0';
    count++;
}

Student::Student(const char* f, const char* n, int g) 
    : grup(g), birthday(1, 1, 2000) {
    fam = new char[strlen(f) + 1];
    name = new char[strlen(n) + 1];
    strcpy(fam, f);
    strcpy(name, n);
    count++;
}

Student::Student(const char* f, const char* n, int g, int d, int m, int y) 
    : grup(g), birthday(d, m, y) {
    fam = new char[strlen(f) + 1];
    name = new char[strlen(n) + 1];
    strcpy(fam, f);
    strcpy(name, n);
    count++;
}

Student::Student(const Student& other) 
    : grup(other.grup), birthday(other.birthday) {
    fam = new char[strlen(other.fam) + 1];
    name = new char[strlen(other.name) + 1];
    strcpy(fam, other.fam);
    strcpy(name, other.name);
    count++;
}

Student::~Student() {
    delete[] fam;
    delete[] name;
    count--;
}

const char* Student::getFam() const { return fam; }
const char* Student::getName() const { return name; }
int Student::getGrup() const { return grup; }
Student::Date Student::getBirthday() const { return birthday; }
int Student::getCount() { return count; }

void Student::setFam(const char* f) {
    delete[] fam;
    fam = new char[strlen(f) + 1];
    strcpy(fam, f);
}

void Student::setName(const char* n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Student::setGrup(int g) { grup = g; }
void Student::setBirthday(int d, int m, int y) { birthday = Date(d, m, y); }

std::string Student::operator-() const {
    std::stringstream ss;
    ss << "Student{fam=" << fam << ", name=" << name 
       << ", grup=" << grup << ", birthday=" << birthday.toString() << "}";
    return ss.str();
}

bool Student::operator==(const Date& d) const { return (birthday == d); }

bool operator==(const Student::Date& d, const Student& s) { return (d == s.getBirthday()); }

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Фамилия: " << s.getFam() 
       << ", Имя: " << s.getName() 
       << ", Группа: " << s.getGrup() 
       << ", Дата рождения: " << s.getBirthday().getDay() 
       << "." << s.getBirthday().getMonth() 
       << "." << s.getBirthday().getYear();
    return os;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] fam;
        delete[] name;
        fam = new char[strlen(other.fam) + 1];
        name = new char[strlen(other.name) + 1];
        strcpy(fam, other.fam);
        strcpy(name, other.name);
        grup = other.grup;
        birthday = other.birthday;
    }
    return *this;
}

void Student::printEntity() {
    std::cout << fam << "\t\t" << name << "\t\t" << grup << "\t\t";
    birthday.printEntity();
    std::cout << std::endl;
}