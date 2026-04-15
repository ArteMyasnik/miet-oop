#include "Invoker.hpp"
#include "../commands/AllCommands.hpp"

Invoker::~Invoker() {
    for (auto const& [key, cmd] : commands) {
        delete cmd;
    }
    commands.clear();
}

void Invoker::setCommand(int key, ICommand* cmd) { commands[key] = cmd; }

void Invoker::init(Database& db) {
    setCommand(1, new AddStudentCommand(db));
    setCommand(2, new PrintCommand(db));
    setCommand(3, new FindFamNameCommand(db));
    setCommand(4, new FilterGroupCommand(db));
    setCommand(5, new UnaryMinusOpeatorCommand(db));
    setCommand(6, new OStreamOperatorCommand(db));
    setCommand(7, new CompareWithDateCommand(db));
}

std::string Invoker::runCommand(int key) {
    if (commands.find(key) != commands.end()) {
        return commands[key]->execute();
    }
    return "Ошибка: Команда с номером " + std::to_string(key) + " не найдена!";
}