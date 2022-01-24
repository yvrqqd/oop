#pragma once

#include <algorithm>
#include "Worker.h"

class SortBlock: public Worker {
private:
    std::vector <std::string> args;
public:
    bool exec(std::vector<std::string>*, std::vector<std::string>*) override;
};
