#pragma once

#include "Reader.h"
#include "GrepBlock.h"
#include "Replace.h"
#include "DumpBlock.h"
#include "Writer.h"
#include "Sort.h"
#include "unordered_map"

class Parser {
public:
    ifstream& stream;
    Parser(ifstream&);
    unordered_map<int, Worker*> commands;
    Worker* make_block(const string&);
    void parse_desc();
    void exec_queue();
};
