#ifndef INVOKER_HPP
#define INVOKER_HPP

#include <map>
#include <string>
#include "../interfaces/ICommand.hpp"

class Database; 

class Invoker {
private:
    std::map<int, ICommand*> commands;

public:
    Invoker() = default;
    ~Invoker();

    void setCommand(int key, ICommand* cmd);
    std::string runCommand(int key);
};

#endif