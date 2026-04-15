#include "CompareWithDateCommand.hpp"
#include <iostream>
#include <sstream>

std::string CompareWithDateCommand::execute() {
    const std::vector<Student*>& list = db.getAll();

    if (list.empty()) {
        return "Ошибка: База данных пуста.";
    }

    int day, month, year;
    std::cout << "\n--- СРАВНЕНИЕ СТУДЕНТА С ДАТОЙ ---\n";
    std::cout << "Введите день: "; std::cin >> day;
    std::cout << "Введите месяц: "; std::cin >> month;
    std::cout << "Введите год: "; std::cin >> year;
    std::cin.ignore(10000, '\n');

    Student::Date targetDate(day, month, year);
    
    std::stringstream ss;
    ss << "\n--- Результат сравнения с датой " << day << "." << month << "." << year << " ---\n";
    ss << "--------------------------------------------------\n";
    
    bool found = false;
    for (auto student : list) {
        if (*student == targetDate) {
            ss << "День рождения совпадает у: " << student->getFam() 
               << " " << student->getName() 
               << " (группа " << student->getGrup() << ")\n";
            found = true;
        }
    }
    
    if (!found) { ss << "Нет студентов с днём рождения " << day << "." << month << "." << year << "\n"; }
    ss << "--------------------------------------------------\n";
    std::cout << ss.str() << std::endl;
    return "Отчет сформирован успешно.";
}