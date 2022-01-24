#pragma once

#include "ReplaceBlock.h"

ReplaceBlock::ReplaceBlock(const std::string& word1, const std::string& word2) {
    args.push_back(word1);
    args.push_back(word2);
}

bool ReplaceBlock::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    (*output) = (*input);
    if(input->empty())
        return true;

    size_t index;
    for(std::string &i : *output) {
        while ((index = i.find(args[0])) != std::string::npos)
            i.replace(index, args[0].size(), args[1]);
    }

    return true;
}
