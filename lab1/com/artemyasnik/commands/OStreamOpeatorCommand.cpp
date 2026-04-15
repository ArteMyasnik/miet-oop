#include "interfaces/OStreamOperator.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

std::string OStreamOperatorCommand::execute() {
    const std::vector<Student*>& list = db.getAll();

    if (list.empty()) { return "Ошибка: База данных пуста."; }

    std::stringstream ss;
    ss << "\n--- Перегрузка операторов (operator<<) ---\n\n";
    ss << "----------------------------------------\n";
    
    ss << "--- Оператор вывода в поток для вывода информации об объекте класса Student--- \n";
    for (auto student : list) {
        ss << "--- " << *student << " --- \n";
    }
    ss << "----------------------------------------\n\n";

    std::cout << ss.str() << std::endl;

    return "Отчет сформирован успешно.";
}