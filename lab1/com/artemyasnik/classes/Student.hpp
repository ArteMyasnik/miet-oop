#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include "../interfaces/IPrintable.hpp"

class Student : public IPrintable {
private:
    char* fam;
    char* name;
    int grup;
    static int count;

public:
    // Внутренний класс Date
    class Date : public IPrintable {
    private:
        int day;
        int month;
        int year;
        
    public:
        Date();
        Date(int d, int m, int y);
        Date(const Date& other);
        ~Date();
        
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        void setDay(int d);
        void setMonth(int m);
        void setYear(int y);
        
        std::string toString() const;
        
        void printEntity() const;
        void printEntity() override;
        
        bool operator==(const Date& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Date& d);
    };

private:
    Date birthday;

public:
    Student();
    Student(const char* f, const char* n, int g);
    Student(const char* f, const char* n, int g, int d, int m, int y);
    Student(const Student& other);
    ~Student();

    const char* getFam() const;
    const char* getName() const;
    int getGrup() const;
    Date getBirthday() const;
    static int getCount();

    void setFam(const char* f);
    void setName(const char* n);
    void setGrup(int g);
    void setBirthday(int d, int m, int y);

    std::string operator-() const;
    bool operator==(const Date& d) const;
    
    friend bool operator==(const Date& d, const Student& s);
    
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    
    Student& operator=(const Student& other);
    
    void printEntity() override;
};

#endif