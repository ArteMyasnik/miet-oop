#ifndef COMPARE_WITH_DATE_COMMAND_HPP
#define COMPARE_WITH_DATE_COMMAND_HPP

#include "../interfaces/ICommand.hpp"
#include "../classes/Database.hpp"

class CompareWithDateCommand : public ICommand {
private:
    Database& db;
public:
    CompareWithDateCommand(Database& d) : db(d) {}
    std::string execute() override;
};

#endif