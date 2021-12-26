#pragma once

#include <algorithm>
#include "Worker.h"

class SortBlock: public Worker {
public:
    bool exec(std::vector<std::string> *input, std::vector<std::string>* output, bool &contain_input, bool &contain_output, unsigned int index) override;
};
