#include "interfaces/FilterGroupCommand.hpp"
#include <iostream>
#include <string>

std::string FilterGroupCommand::execute() {
    int g;

    std::cout << "--- ФИЛЬТР ПО НОМЕРУ ГРУППЫ ---" << std::endl;
    std::cout << "Введите номер группы: "; 
    
    if (!(std::cin >> g)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "---------------------------------------" << std::endl;
        return "Ошибка: Номер группы должен быть числом!";
    }
    std::cin.ignore(10000, '\n');
    std::cout << "---------------------------------------" << std::endl;

    db.filterByGroup(g);

    return "Система: Фильтрация по группе " + std::to_string(g) + " завершена.";
}