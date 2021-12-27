#pragma once

#include "Worker.h"

class DumpBlock: public Worker {
private:
    std::vector<std::string> args;
public:
    Dump(std::string filename);
    bool exec(std::vector<std::string> *input, std::vector<std::string> *output) override;
};
