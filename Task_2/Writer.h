#pragma once
#include "Worker.h"

class Writer: public Worker{
private:
    std::vector <std::string> args;
public:
    WriteFile(std::string);
    bool exec(std::vector<std::string>*, std::vector<std::string>*) override;
};
