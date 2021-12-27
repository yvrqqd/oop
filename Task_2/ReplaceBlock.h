#pragma once

#include "Worker.h"

class ReplaceBlock: public Worker {
private:
    std::vector <std::string> args;
public:
    Replace(const std::string&, const std::string&);
    bool exec(std::vector<std::string>*, std::vector<std::string>*) override;
};
