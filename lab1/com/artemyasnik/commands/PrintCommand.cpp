#include "PrintCommand.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

std::string PrintCommand::execute() {
    const std::vector<Student*>& list = db.getAll();

    if (list.empty()) {
        return "Ошибка: База данных пуста.";
    }

    std::cout << std::left 
              << std::setw(20) << "Фамилия" 
              << std::setw(20) << "Имя" 
              << std::setw(10) << "Группа" 
              << std::endl;
    
    std::cout << "------------------------------------------------------" << std::endl;

    for (auto student : list) {
        std::cout << std::left 
                  << std::setw(20) << student->getFam()
                  << std::setw(20) << student->getName()
                  << std::setw(10) << student->getGrup()
                  << std::endl;
    }

    std::cout << "------------------------------------------------------" << std::endl;
    
    std::cout << "Количество записей в базе: " << list.size() << std::endl;

    return "Отчет сформирован успешно.";
}