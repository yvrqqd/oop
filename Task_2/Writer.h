#pragma once
#include "Worker.h"

class Writer: public Worker{
private:
    vector <string> args;
public:
    WriteFile(string out);
    bool exec(vector<string> *input, vector<string> *output) override;
};
