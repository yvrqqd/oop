#include "Reader.h"

bool Reader::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    string line;
    ifstream stream(args[0]);
    while (getline(stream,line)){
        output->push_back(line);
    }
    stream.close();
    return true;
}

Reader::ReadFile(std::string input) {
    args.push_back(input);
}
