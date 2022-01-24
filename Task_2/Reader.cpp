#include "Reader.h"

bool Reader::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    std::string line;
    std::ifstream stream(args[0]);
    while (getline(stream,line)){
        output->push_back(line);
    }
    stream.close();
    return true;
}

Reader::Reader(const std::string& input) {
    args.push_back(input);
}
