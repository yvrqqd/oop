#include "Writer.h"

Writer::Writer(const std::string& out) {
    args.push_back(out);
}

bool Writer::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    std::ofstream stream(args[0]);
    for (auto &i : *input){
        stream << i <<std::endl;
    }
    return true;
}
