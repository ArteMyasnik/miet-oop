#ifndef PRINT_COMMAND_HPP
#define PRINT_COMMAND_HPP

#include "../interfaces/ICommand.hpp"
#include "../classes/Database.hpp"

class PrintCommand : public ICommand {
private:
    Database& db;
public:
    PrintCommand(Database& d) : db(d) {}
    std::string execute() override;
};

#endif