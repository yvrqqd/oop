#pragma once

#include "Worker.h"

class DumpBlock: public Worker {
private:
    std::vector<std::string> args;
public:
    explicit DumpBlock(const std::string& filename);
    bool exec(std::vector<std::string> *, std::vector<std::string> *) override;
};
