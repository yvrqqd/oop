#pragma once

#include "Worker.h"

class GrepBlock: public Worker {
private:
    std::vector <std::string> args;
public:
    GrepBlock(std::string);
    GrepBlock(std::string &&);
    bool exec(std::vector<std::string> *input, std::vector<std::string>* output,
              bool &contain_input, bool &contain_output, unsigned int index) override;
};
