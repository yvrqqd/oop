#pragma once

#include "Worker.h"

class GrepBlock: public Worker {
private:
    std::vector <std::string> args;
public:
    explicit GrepBlock(const std::string&);
    explicit GrepBlock(std::string &&);

    bool exec(std::vector<std::string>*, std::vector<std::string>*);
};
