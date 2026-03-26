#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <clocale>
#include "com/artemyasnik/classes/Database.hpp"
#include "com/artemyasnik/classes/Invoker.hpp"

void printMenu() {
    const int menuWidth = 45;
    std::cout << std::setfill('.');

    std::cout << std::left << std::setw(menuWidth) << "Добавить новый элемент " << " 1" << std::endl;
    std::cout << std::left << std::setw(menuWidth) << "Распечатать базу студентов " << " 2" << std::endl;
    std::cout << std::left << std::setw(menuWidth) << "Поиск студента по ФИО " << " 3" << std::endl;
    std::cout << std::left << std::setw(menuWidth) << "Фильтр по номеру группы " << " 4" << std::endl;
    std::cout << std::left << std::setw(menuWidth) << "Выход из программы " << " 5" << std::endl;

    std::cout << std::setfill(' ');
    
    std::cout << std::string(menuWidth + 5, '-') << std::endl;
    std::cout << "Введите номер функции: ";
}

int getValidatedChoice() {
    int choice;
    
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    Database db;
    db.loadFromFile("database.txt"); 

    Invoker invoker;
    invoker.init(db);

    while (true) {
        printMenu();
        
        int choice = getValidatedChoice();

        if (choice == -1) {
            std::cout << "\n[Ошибка]: Пожалуйста, введите целое число!" << std::endl;
            continue;
        }
        if (choice == 5) { break; }
        std::string result = invoker.runCommand(choice);
        std::cout << "\n>>> " << result << "\n" << std::endl;
    }

    db.saveToFile("database.txt");
    std::cout << "Данные сохранены. Выход" << std::endl;

    return 0;
}