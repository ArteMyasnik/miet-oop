#ifndef UNARY_MINUS_OPERATOR_COMMAND_HPP
#define UNARY_MINUS_OPERATOR_COMMAND_HPP

#include "../interfaces/ICommand.hpp"
#include "../classes/Database.hpp"

class UnaryMinusOpeatorCommand : public ICommand {
private:
    Database& db;
public:
    UnaryMinusOpeatorCommand(Database& d) : db(d) {}
    std::string execute() override;
};

#endif