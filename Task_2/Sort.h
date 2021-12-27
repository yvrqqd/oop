#pragma once

#include <algorithm>
#include "Worker.h"

class SortBlock: public Worker {
public:
    bool exec(std::vector<std::string>*, std::vector<std::string>*, bool&, bool&, unsigned int) override;
};
