#include "CompareWithDateCommand.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

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
    
    std::vector<Student*> found;
    std::copy_if(list.begin(), list.end(), std::back_inserter(found),
        [&targetDate](Student* s) {
            return *s == targetDate;
        });
    
    if (!found.empty()) {
        std::for_each(found.begin(), found.end(),
            [&ss](Student* s) {
                ss << *s << std::endl;
            });
    } else {
        ss << "Нет студентов с днём рождения " << day << "." << month << "." << year << "\n";
    }
    
    ss << "--------------------------------------------------\n";
    std::cout << ss.str() << std::endl;
    return "Отчет сформирован успешно.";
}