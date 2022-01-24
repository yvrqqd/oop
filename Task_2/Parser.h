#pragma once

#include "Reader.cpp"
#include "GrepBlock.cpp"
#include "ReplaceBlock.cpp"
#include "DumpBlock.cpp"
#include "Writer.cpp"
#include "Sort.cpp"
#include <unordered_map>

class Parser {
public:
    std::ifstream& stream;
    Parser(std::ifstream&);
    std::unordered_map<int, Worker*> commands;
    Worker* make_block(const std::string&);
    void parse_desc();
    void exec_queue();
};
