#ifndef FIND_FAM_NAME_COMMAND_HPP
#define FIND_FAM_NAME_COMMAND_HPP

#include "../interfaces/ICommand.hpp"
#include "../classes/Database.hpp"

class FindFamNameCommand : public ICommand {
private:
    Database& db;
public:
    FindFamNameCommand(Database& d) : db(d) {}
    std::string execute() override;
};

#endif