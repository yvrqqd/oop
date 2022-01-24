#pragma once

#include <fstream>
#include "Worker.h"

class Reader: public Worker {
private:
    std::vector<std::string> args;
public:
    explicit Reader(const std::string&);
    bool exec(std::vector<std::string> *, std::vector<std::string> *) override;
};
