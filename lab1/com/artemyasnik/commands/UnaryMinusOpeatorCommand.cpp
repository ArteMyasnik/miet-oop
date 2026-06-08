#include "interfaces/UnaryMinusOpeatorCommand.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>

std::string UnaryMinusOpeatorCommand::execute() {
    const std::vector<Student*>& list = db.getAll();

    if (list.empty()) { return "Ошибка: База данных пуста."; }

    std::stringstream ss;
    ss << "\n--- Перегрузка операторов (унарный минус) ---\n\n";
    ss << "----------------------------------------\n";
    ss << "--- Унарный минус для вывода информации об объекте класса Student--- \n";
    
    std::for_each(list.begin(), list.end(),
        [&ss](Student* student) {
            ss << "--- " << -(*student) << " --- \n";
        });
    
    ss << "----------------------------------------\n\n";

    std::cout << ss.str() << std::endl;

    return "Отчет сформирован успешно.";
}