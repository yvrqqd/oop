#pragma once

#include "Worker.h"

class GrepBlock: public Worker {
private:
    std::vector <std::string> args;
public:
    GrepBlock(std::string);
    GrepBlock(std::string &&);
    bool exec(std::vector<std::string>*, std::vector<std::string>* ,
              bool&, bool&, unsigned int) override;
};
