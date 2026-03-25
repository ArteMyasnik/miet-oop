#ifndef FILTER_GROUP_COMMAND_HPP
#define FILTER_GROUP_COMMAND_HPP

#include "../interfaces/ICommand.hpp"
#include "../classes/Database.hpp"

class FilterGroupCommand : public ICommand {
private:
    Database& db;
public:
    FilterGroupCommand(Database& d) : db(d) {}
    std::string execute() override;
};

#endif