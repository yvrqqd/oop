#pragma once

#include <vector>
#include <string>
#include "Validator.cpp"

class Worker {
protected:
    std::vector<std::string> args;
public:
    virtual ~Worker() = default;
    virtual bool exec(std::vector<std::string> *, std::vector<std::string> *) = 0;
};
