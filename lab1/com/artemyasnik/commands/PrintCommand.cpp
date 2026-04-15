#include "interfaces/PrintCommand.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

std::string PrintCommand::execute() {
    const std::vector<Student*>& list = db.getAll();

    if (list.empty()) { return "Ошибка: База данных пуста."; }

    std::cout << "\nФамилия\t\tИмя\t\tГруппа\t\tДата рождения" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;

    for (auto student : list) {
        std::cout << student->getFam() << "\t\t"
                  << student->getName() << "\t\t"
                  << student->getGrup() << "\t\t"
                  << student->getBirthday().getDay() << "."
                  << student->getBirthday().getMonth() << "."
                  << student->getBirthday().getYear() << std::endl;
    }
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "Количество записей в базе: " << list.size() << std::endl;
    std::cout << "Статический счётчик объектов Student: " << Student::getCount() << std::endl;
    
    if (list.size() != static_cast<size_t>(Student::getCount())) {
        std::cout << "[ВНИМАНИЕ]: Размер базы (" << list.size() 
           << ") не совпадает со счётчиком (" << Student::getCount() << ")!\n";
    }

    return "Отчет сформирован успешно.";
}