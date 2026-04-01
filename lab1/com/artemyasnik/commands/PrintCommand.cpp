#include "interfaces/PrintCommand.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

std::string PrintCommand::execute() {
    const std::vector<Student*>& list = db.getAll();

    if (list.empty()) { return "Ошибка: База данных пуста."; }

    std::cout << "\nФамилия\t\tИмя\t\tГруппа" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for (auto student : list) {
        std::cout << student->getFam() << "\t\t"
                  << student->getName() << "\t\t"
                  << student->getGrup() << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Количество записей в базе: " << list.size() << std::endl;

    return "Отчет сформирован успешно.";
}