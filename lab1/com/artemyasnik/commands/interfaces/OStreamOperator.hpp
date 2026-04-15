#ifndef OSTREAM_OPERATOR_COMMAND_HPP
#define OSTREAM_OPERATOR_COMMAND_HPP

#include "../interfaces/ICommand.hpp"
#include "../classes/Database.hpp"

class OStreamOperatorCommand : public ICommand {
private:
    Database& db;
public:
    OStreamOperatorCommand(Database& d) : db(d) {}
    std::string execute() override;
};

#endif