#pragma once
#include "Worker.h"

class Writer: public Worker{
private:
    std::vector <std::string> args;
public:
    WriteFile(std::string out);
    bool exec(std::vector<std::string> *input, std::vector<std::string> *output) override;
};
