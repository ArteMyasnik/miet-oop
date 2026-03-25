#include "FindFamNameCommand.hpp"
#include <iostream>

std::string FindFamNameCommand::execute() {
    char searchFam[100];
    char searchName[100];

    std::cout << "--- ПОИСК СТУДЕНТА ПО ФИО ---" << std::endl;
    std::cout << "Введите фамилию: "; std::cin >> searchFam;
    std::cout << "Введите имя: ";     std::cin >> searchName;
    std::cout << "---------------------------------------" << std::endl;

    db.findByName(searchFam, searchName);

    return "Запрос на поиск студента " + std::string(searchFam) + " обработан.";
}