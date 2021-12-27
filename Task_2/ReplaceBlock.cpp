#pragma once

#include "ReplaceBlock.h"

ReplaceBlock::Replace(const string& word1, const string& word2) {
    args.push_back(word1);
    args.push_back(word2);
}

bool ReplaceBlock::exec(std::vector<std::string> *input, std::vector<std::string> *output,
                        bool &contain_input, bool &contain_output, unsigned int ind) {
    if(!contain_input)
        throw logic_error("No input on replace, Block index: " + to_string(ind));

    (*output) = (*input);
    if(input->empty())
        return true;

    size_t index;
    for(string &i : *output)
        while ((index = i.find(args[0])) != std::string::npos)
            i.replace(index, args[0].size(), args[1]);

    contain_output = true;
    return true;
}
