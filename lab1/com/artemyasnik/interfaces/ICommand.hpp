#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP
#include <string>

class ICommand {
public:
    virtual ~ICommand() {}
    virtual std::string execute() = 0; 
};

#endif