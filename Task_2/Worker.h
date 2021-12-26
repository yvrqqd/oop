#pragma once

#include <vector>
#include <string>
#include "Validator.cpp"

class Worker {
public:
    virtual ~Worker() = default;
    virtual bool exec(std::vector <std::string> *input, std::vector <std::string> * output) = 0;
};
