#pragma once

#include "Worker.h"

class ReplaceBlock: public Worker {
public:
    Replace(const std::string&, const std::string&);
    bool exec(std::vector<std::string> *input, std::vector<std::string> *output) override;
};
