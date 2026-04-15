#include "interfaces/AddStudentCommand.hpp"
#include "../utils/StudentValidator.hpp"
#include "../exceptions/AllExceptions.hpp"
#include <iostream>
#include <sstream>
#include <string>

std::string AddStudentCommand::execute() {
    char f[100], n[100];
    int g;
    int day, month, year;

    std::cout << "--- ВВОД ДАННЫХ СТУДЕНТА ---" << std::endl;
    std::cout << "Фамилия: "; std::cin >> f;
    std::cout << "Имя:     "; std::cin >> n;
    std::cout << "Группа:  "; std::cin >> g;
    std::cout << "День рождения: "; std::cin >> day;
    std::cout << "Месяц рождения: "; std::cin >> month;
    std::cout << "Год рождения:  "; std::cin >> year;

    std::cin.ignore(10000, '\n');

    try {
        StudentValidator validator(f, n, g, day, month, year);
        validator.validate();
        db.add(new Student(f, n, g, day, month, year));
        
        std::stringstream ss;
        ss << "Система: Студент " << f << " успешно добавлен. Дата рождения: " 
           << day << "." << month << "." << year;
        return ss.str();

    } catch (const ValidationError& e) { 
        return e.what(); 
    }
}