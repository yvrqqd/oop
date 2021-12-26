#include "Writer.h"

Writer::WriteFile(std::string out) {
    args.push_back(out);
}

bool Writer::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    ofstream stream(args[0]);
    for (auto &i : *input){
        stream << i <<endl;
    }
    return true;
}
