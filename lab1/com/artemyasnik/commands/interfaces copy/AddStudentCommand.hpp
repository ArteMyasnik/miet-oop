#ifndef ADD_STUDENT_COMMAND_HPP
#define ADD_STUDENT_COMMAND_HPP

#include "../interfaces/ICommand.hpp"
#include "../classes/Database.hpp"

class AddStudentCommand : public ICommand {
private:
    Database& db;
public:
    AddStudentCommand(Database& d) : db(d) {}
    std::string execute() override;
};

#endif