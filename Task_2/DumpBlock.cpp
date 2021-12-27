#include "Dump.h"

DumpBlock::Dump(std::string filename) {
    args.push_back(filename);
}

bool DumpBlock::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    ofstream stream(args[0]);
    for (auto& i : *input){
        stream<<i<<endl;
        output->push_back(i);
    }
    stream.close();
    return true;
}
