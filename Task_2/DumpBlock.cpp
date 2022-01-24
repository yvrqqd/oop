#include "DumpBlock.h"

DumpBlock::DumpBlock(const std::string& filename) {
    args.push_back(filename);
}

bool
DumpBlock::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    std::ofstream stream(args[0]);
    if (!stream) {
        Validator::file_error("File " + args[0] + " not opened!");
        return false;
    }

    for (auto &i: *input) {
        stream << i << std::endl;
        output->push_back(i);
    }
    stream.close();
    return true;
}

