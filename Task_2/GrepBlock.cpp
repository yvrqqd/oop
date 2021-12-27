#include "Grep.h"

GrepBlock::GrepBlock(std::string && word) {
    args.push_back(word);
    word = nullptr;
}

GrepBlock::GrepBlock(std::string word) {
    args.push_back(word);
}

bool GrepBlock::exec(std::vector<std::string> *input, std::vector<std::string> *output,
                     bool &contain_input, bool &contain_output, unsigned int index) {
    if(!contain_input)
        throw logic_error("No input on grep, block index: " + to_string(index));
    if(input->empty())
    {
        (*output) = (*input);
        return true;
    }

    (*output).clear();
    for(const auto &i : *input)
        if(i.find(args[0]) != std::string::npos)
            output->push_back(i);

    contain_output = true;
    return true;
}
