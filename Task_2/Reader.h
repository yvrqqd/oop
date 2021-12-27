#pragma once

#include <fstream>
#include "Worker.h"

class Reader:public Worker {
private:
    std::vector<std::string> args;
public:
    ReadFile(std::string);
    bool exec(std::vector<std::string>*, std::vector<std::string>*) override;
};
