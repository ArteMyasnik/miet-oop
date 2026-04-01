#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <clocale>
#include "com/artemyasnik/classes/Database.hpp"
#include "com/artemyasnik/classes/Invoker.hpp"

void printMenu() {
    std::cout << "\n";
    std::cout << "1\tДобавить новый элемент" << std::endl;
    std::cout << "2\tРаспечатать базу студентов" << std::endl;
    std::cout << "3\tПоиск студента по ФИО" << std::endl;
    std::cout << "4\tФильтр по номеру группы" << std::endl;
    std::cout << "5\tВыход из программы" << std::endl;
    std::cout << "------------------------" << std::endl;
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