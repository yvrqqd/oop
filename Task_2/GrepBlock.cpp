#include "GrepBlock.h"


GrepBlock::GrepBlock(std::string && word) {
    args.push_back(word);
    word = nullptr;
}

GrepBlock::GrepBlock(const std::string& word) {
    args.push_back(word);
}

bool GrepBlock::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    if(input->empty())
    {
        (*output) = (*input);
        return true;
    }

    (*output).clear();
    for(const auto &i : *input)
        if(i.find(args[0]) != std::string::npos)
            output->push_back(i);

    return true;
}
