#include "interfaces/AddStudentCommand.hpp"
#include "../utils/StudentValidator.hpp"
#include "../exceptions/AllExceptions.hpp"
#include <iostream>

std::string AddStudentCommand::execute() {
    char f[100], n[100];
    int g;

    std::cout << "--- ВВОД ДАННЫХ СТУДЕНТА ---" << std::endl;
    std::cout << "Фамилия: "; std::cin >> f;
    std::cout << "Имя:     "; std::cin >> n;
    std::cout << "Группа:  "; std::cin >> g;

    std::cin.ignore(10000, '\n');

    try {
        StudentValidator validator(f, n, g);
        validator.validate(); 

        db.add(new Student(f, n, g));
        
        return "Система: Студент " + std::string(f) + " успешно добавлен.";

    } catch (const ValidationError& e) { return e.what(); }
}